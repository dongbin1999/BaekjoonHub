#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
ll h[1000][1000],c[1000001],ans[1001][1001];
int u[1000001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],c[x]+=c[y],u[y]=x;
    return 1;
}


int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(u,-1,sizeof(u));
    map<ll,vector<pii>> ma;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        scanf("%lld",&h[i][j]);
        ma[h[i][j]].push_back({i,j});
    }
    for(int i=0;i<n*m;i++)scanf("%lld",&c[i]);
    for(auto [H,xy]:ma){
        for(auto [x,y]:xy){
            int me=x*m+y;
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                int next=nx*m+ny;
                if(h[nx][ny]<=h[x][y])merge(me,next);
            }
        }
        for(auto [x,y]:xy){
            int me=find(x*m+y);
            ans[x][y]=c[me];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%lld ",ans[i][j]);
        printf("\n");
    }
}