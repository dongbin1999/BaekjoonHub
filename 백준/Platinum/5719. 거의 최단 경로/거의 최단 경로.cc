#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void init(vector<vector<pii>>&graph,vector<int>&dist,vector<int>&rdist,int d){
    int n=graph.size();
    vector<vector<pii>> tmp(n);
    for(int i=0;i<n;i++)for(auto [v,p]:graph[i])
        if(dist[i]+rdist[v]+p>dist[d])tmp[i].push_back({v,p});
    graph=tmp;
}
void dijkstra(vector<int>&dist,int s,vector<vector<pii>>&graph){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto[cost,node]=pq.top();pq.pop();
        if(dist[node]<1e9)continue;
        dist[node]=cost;
        for(auto [nx,c]:graph[node])
            pq.push({cost+c,nx});
    }
}

void solve(int n,int m){
    int s,d;scanf("%d%d",&s,&d);
    vector<int> dist(n,1e9),rdist(n,1e9);
    vector<vector<pii>> graph(n),rev(n);
    while(m--){
        int u,v,p;scanf("%d%d%d",&u,&v,&p);
        graph[u].push_back({v,p});
        rev[v].push_back({u,p});
    }
    dijkstra(dist,s,graph),dijkstra(rdist,d,rev);
    init(graph,dist,rdist,d),dist.assign(n,1e9);
    dijkstra(dist,s,graph);
    printf("%d\n",dist[d]<1e9?dist[d]:-1);
}

int main() {
    while(1){
        int n,m;scanf("%d%d",&n,&m);
        if(!n)break;
        solve(n,m);
    }
}