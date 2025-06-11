#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;

int a[1001][1001],d[1001][1001];
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    memset(d,0x3f,sizeof(d));
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    pq.push({0,1,1});
    while(!pq.empty()){
        auto [dist,x,y]=pq.top();pq.pop();
        if(d[x][y]<=dist)continue;
        d[x][y]=dist;
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<1||nx>n||ny<1||ny>n)continue;
            int nd=max(dist,abs(a[x][y]-a[nx][ny]));
            pq.push({nd,nx,ny});
        }
    }
    printf("%d",d[n][n]);
    return 0;
}