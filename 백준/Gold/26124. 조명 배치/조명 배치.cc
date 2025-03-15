#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> arr;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[1002][1002],b[1002][1002];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<arr> v;
    memset(a,0x3f,sizeof(a)),memset(b,-0x3f,sizeof(b));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        if(a[i][j]>-1)v.push_back({a[i][j],i,j});
        else b[i][j]=-1;
    }
    sort(v.begin(),v.end(),greater<arr>());
    int cnt=0;
    for(auto [l,ix,iy]:v){
        if(b[ix][iy]>-1e9)continue;
        queue<arr> q;q.push({l,ix,iy}),b[ix][iy]=l;
        if(l)cnt++;else continue;
        while(!q.empty()){
            auto [li,x,y]=q.front();q.pop();
            if(li<a[x][y]||a[x][y]==-1)continue;
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(a[nx][ny]<li-1&&a[nx][ny]!=-1)return !printf("-1");
                if(li-1<a[nx][ny])continue;
                if(a[nx][ny]==-1)b[nx][ny]=-1;
                else if(b[nx][ny]<-1e9&&li)q.push({li-1,nx,ny}),b[nx][ny]=li-1;
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++)printf("%d ",b[i][j]);
//        printf("\n");
//    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!=b[i][j])return !printf("-1");
    printf("%d",cnt);
}