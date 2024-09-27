#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[1002][1002],d[1002][1002],xs[1001][1001],ys[1001][1001];

int main() {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        xs[i][j]+=xs[i][j-1]+a[i][j],ys[i][j]=ys[i-1][j]+a[i][j];
    int h,w,sx,sy,ex,ey;scanf("%d%d%d%d%d%d",&h,&w,&sx,&sy,&ex,&ey);
    memset(d,-1,sizeof(d));d[sx][sy]=0;
    queue<pii> q;q.push({sx,sy});
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(auto [dx,dy]:go){
            int nx1=x+dx,ny1=y+dy,nx2=nx1+h-1,ny2=ny1+w-1;
            if(nx1<1||nx2>n||ny1<1||ny2>m||d[nx1][ny1]!=-1)continue;
            if(xs[nx1][ny2]-xs[nx1][ny1-1])continue;
            if(xs[nx2][ny2]-xs[nx2][ny1-1])continue;
            if(ys[nx2][ny1]-ys[nx1-1][ny1])continue;
            if(ys[nx2][ny2]-ys[nx1-1][ny2])continue;
            d[nx1][ny1]=d[x][y]+1,q.push({nx1,ny1});
        }
    }
    printf("%d",d[ex][ey]);
}