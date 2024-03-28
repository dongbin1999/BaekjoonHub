#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
int d[1001][1001],mn,pre[1001];

void dijkstra(int n){
    vector<int> x(n+1,1e9);
    priority_queue<tup,vector<tup>,greater<tup>>pq;
    pq.push({0,1,-1});
    while(!pq.empty()){
        auto[dist,cur,p]=pq.top();pq.pop();
        if(x[cur]<1e9)continue;
        x[cur]=dist,pre[cur]=p;
        for(int i=1;i<=n;i++)if(d[cur][i]<1e9)
            pq.push({dist+d[cur][i],i,cur});
    }
    mn=max(mn,x[n]);
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    while(m--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        d[x][y]=d[y][x]=z;
    }
    dijkstra(n);
    vector<pair<int,int>> v;
    int x=n;
    while(pre[x]!=-1)v.push_back({x,pre[x]}),x=pre[x];
    for(auto [a,b]:v){
        int rollback=d[a][b];
        d[a][b]=d[b][a]=1e9;
        dijkstra(n);
        d[a][b]=d[b][a]=rollback;
    }
    printf("%d",mn);
}