#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> arr;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int dist[503][503];

void solve(){
    int n,m,d;scanf("%d%d%d",&n,&m,&d);
    vector<vector<char>> a(n+2,vector<char>(m+2));
    int x,y;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        scanf(" %c",&a[i][j]);
        if(a[i][j]=='S')x=i,y=j;
    }
    for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)dist[i][j]=1e9;
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    pq.push({0,x,y});
    int ans=1e9;
    while(!pq.empty()){
        auto [cd,cx,cy]=pq.top();pq.pop();
        if(dist[cx][cy]<=cd)continue;dist[cx][cy]=cd;
        if(!cx||cx==n+1||!cy||cy==m+1)ans=min(ans,cd);
        for(auto [dx,dy]:go){
            int nx=cx+dx,ny=cy+dy;
            if(nx<0||nx>n+1||ny<0||ny>m+1||a[nx][ny]=='#')continue;
            pq.push({cd+(a[nx][ny]=='@'?d+1:1),nx,ny});
        }
    }
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}