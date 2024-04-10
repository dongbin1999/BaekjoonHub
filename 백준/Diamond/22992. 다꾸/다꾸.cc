#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=2e18;
struct element{ll l_x,x_r,x_x,sum;};
vector<vector<element>> row,col;
int csz,rsz;

void update(ll x,ll y,ll val){
    ll xx=x,yy=y;
    y+=csz,row[x][y]={val,val,val,val};
    while(y>1){
        y/=2;
        row[x][y].l_x=max(row[x][y*2].l_x,row[x][y*2].sum+row[x][y*2+1].l_x);
        row[x][y].x_r=max(row[x][y*2].x_r+row[x][y*2+1].sum,row[x][y*2+1].x_r);
        row[x][y].x_x=max({row[x][y*2].x_x,row[x][y*2+1].x_x,row[x][y*2].x_r+row[x][y*2+1].l_x});
        row[x][y].sum=row[x][y*2].sum+row[x][y*2+1].sum;
    }
    x=xx,y=yy;
    x+=rsz,col[x][y]={val,val,val,val};
    while(x>1){
        x/=2;
        col[x][y].l_x=max(col[x*2][y].l_x,col[x*2][y].sum+col[x*2+1][y].l_x);
        col[x][y].x_r=max(col[x*2][y].x_r+col[x*2+1][y].sum,col[x*2+1][y].x_r);
        col[x][y].x_x=max({col[x*2][y].x_x,col[x*2+1][y].x_x,col[x*2][y].x_r+col[x*2+1][y].l_x});
        col[x][y].sum=col[x*2][y].sum+col[x*2+1][y].sum;
    }
}
element query(int s,int e,int fix,int node,int ns,int ne,bool rc){
    if(e<ns||ne<s)return {-inf,-inf,-inf,0};
    if(s<=ns&&ne<=e)return rc?col[node][fix]:row[fix][node];
    int mid=(ns+ne)>>1;
    element l=query(s,e,fix,node<<1,ns,mid,rc),r=query(s,e,fix,node<<1|1,mid+1,ne,rc);
    return {max(l.l_x,l.sum+r.l_x),max(r.x_r,l.x_r+r.sum),max({l.x_x,r.x_x,l.x_r+r.l_x}),l.sum+r.sum};
}

vector<vector<element>> rowmn,colmn;
void updatemn(ll x,ll y,ll val){
    ll xx=x,yy=y;
    y+=csz,rowmn[x][y]={val,val,val,val};
    while(y>1){
        y/=2;
        rowmn[x][y].l_x=min(rowmn[x][y*2].l_x,rowmn[x][y*2].sum+rowmn[x][y*2+1].l_x);
        rowmn[x][y].x_r=min(rowmn[x][y*2].x_r+rowmn[x][y*2+1].sum,rowmn[x][y*2+1].x_r);
        rowmn[x][y].x_x=min({rowmn[x][y*2].x_x,rowmn[x][y*2+1].x_x,rowmn[x][y*2].x_r+rowmn[x][y*2+1].l_x});
        rowmn[x][y].sum=rowmn[x][y*2].sum+rowmn[x][y*2+1].sum;
    }
    x=xx,y=yy;
    x+=rsz,colmn[x][y]={val,val,val,val};
    while(x>1){
        x/=2;
        colmn[x][y].l_x=min(colmn[x*2][y].l_x,colmn[x*2][y].sum+colmn[x*2+1][y].l_x);
        colmn[x][y].x_r=min(colmn[x*2][y].x_r+colmn[x*2+1][y].sum,colmn[x*2+1][y].x_r);
        colmn[x][y].x_x=min({colmn[x*2][y].x_x,colmn[x*2+1][y].x_x,colmn[x*2][y].x_r+colmn[x*2+1][y].l_x});
        colmn[x][y].sum=colmn[x*2][y].sum+colmn[x*2+1][y].sum;
    }
}
element querymn(int s,int e,int fix,int node,int ns,int ne,bool rc){
    if(e<ns||ne<s)return {inf,inf,inf,0};
    if(s<=ns&&ne<=e)return rc?colmn[node][fix]:rowmn[fix][node];
    int mid=(ns+ne)>>1;
    element l=querymn(s,e,fix,node<<1,ns,mid,rc),r=querymn(s,e,fix,node<<1|1,mid+1,ne,rc);
    return {min(l.l_x,l.sum+r.l_x),min(r.x_r,l.x_r+r.sum),min({l.x_x,r.x_x,l.x_r+r.l_x}),l.sum+r.sum};
}

int main(){
    int h,w,t;scanf("%d%d%d",&h,&w,&t);
    rsz=1<<(32-__builtin_clz(h+1)),csz=1<<(32-__builtin_clz(w+1));
    row.assign(h+1,vector<element>(csz<<1));rowmn.assign(h+1,vector<element>(csz<<1));
    col.assign(rsz<<1,vector<element>(w+1));colmn.assign(rsz<<1,vector<element>(w+1));
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
            int a;scanf("%d",&a);
            update(i,j,a);updatemn(i,j,a);
        }
    while(t--){
        int op;scanf("%d",&op);
        if(op==1){
            int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            element u=query(y1,y2,x1,1,0,csz-1,0),d=query(y1,y2,x2,1,0,csz-1,0),
                    l=query(x1,x2,y1,1,0,rsz-1,1),r=query(x1,x2,y2,1,0,rsz-1,1);
            element e[4]={u,r,d,l};
            element udel=query(y1,y2-1,x1,1,0,csz-1,0),ddel=query(y1+1,y2,x2,1,0,csz-1,0),
                    ldel=query(x1+1,x2,y1,1,0,rsz-1,1),rdel=query(x1,x2-1,y2,1,0,rsz-1,1);
            element edel[4]={udel,rdel,ddel,ldel};
            element umn=querymn(y1,y2,x1,1,0,csz-1,0),dmn=querymn(y1,y2,x2,1,0,csz-1,0),
                    lmn=querymn(x1,x2,y1,1,0,rsz-1,1),rmn=querymn(x1,x2,y2,1,0,rsz-1,1);
            element emn[4]={umn,rmn,dmn,lmn};
            ll ul=row[x1][y1+csz].sum,ur=row[x1][y2+csz].sum,dl=row[x2][y1+csz].sum,dr=row[x2][y2+csz].sum;
            ll del[4]={ul,ur,dr,dl},ans=-inf;
            for(int i=0;i<4;i++){
                ans=max(ans,e[i].x_x);
                ll val=i<2?e[i].x_r:e[i].l_x;
                for(int go=1;go<4;go++){
                    int j=(i+go)%4;
                    ll add=j<2?(go==3?edel:e)[j].l_x:(go==3?edel:e)[j].x_r;
                    add-=del[j];
                    ans=max(ans,val+add);
                    val+=e[j].sum-del[j];
                }
                val=emn[i].sum-emn[i].x_x;
                for(int go=0;go<4;go++){
                    int j=(i+go)%4;
                    if(j!=i)val+=emn[j].sum;
                    val-=del[j];
                }
                ans=max(ans,val);
            }
            printf("%lld\n",ans);
        }
        else{
            int x,y,p;scanf("%d%d%d",&x,&y,&p);
            update(x,y,p);updatemn(x,y,p);
        }
    }
    return 0;
}