#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[1001][1001],vis[1001][1001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    tup cur={0,0,0};
    priority_queue<tup> pq;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        if(i==1||j==1||i==n||j==m)pq.push({a[i][j],i,j}),vis[i][j]=1;
    }
    int k;scanf("%d",&k);
    while(k--&&!pq.empty()){
        auto [v,x,y]=pq.top();pq.pop();
        printf("%d %d\n",x,y);
        for(auto [dx,dy]:go){
            int nx=dx+x,ny=dy+y;
            if(nx>=1&&nx<=n&&ny>=0&&ny<=m&&!vis[nx][ny])vis[nx][ny]=1,pq.push({a[nx][ny],nx,ny});
        }
    }
    return 0;
}