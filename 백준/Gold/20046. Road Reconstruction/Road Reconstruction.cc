#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> arr;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[1001][1001],d[1001][1001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    memset(d,0x3f,sizeof(d));
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    if(a[0][0]==-1)return !printf("-1");
    pq.push({a[0][0],0,0});
    while(!pq.empty()){
        auto [dist,x,y]=pq.top();pq.pop();
        if(d[x][y]<=dist)continue;
        d[x][y]=dist;
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<0||nx>=n||ny<0||ny>=m||d[nx][ny]<1e9||a[nx][ny]==-1)continue;
            pq.push({a[nx][ny]+dist,nx,ny});
        }
    }
    printf("%d",d[n-1][m-1]>1e9?-1:d[n-1][m-1]);
}