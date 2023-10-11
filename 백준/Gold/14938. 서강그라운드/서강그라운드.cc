#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> graph[101];
int item[101];
int dijkstra(int s,int n,int m){
    vector<int> dist(n+1,1e9);
    int ret=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;pq.push({0,s});
    while(!pq.empty()){
        auto [d,node]=pq.top();pq.pop();
        if(dist[node]<1e9)continue;
        dist[node]=d,ret+=item[node];
        for(auto [nx,cost]:graph[node])
            if(d+cost<=m)pq.push({d+cost,nx});
    }
    return ret;
}

int main(){
    int n,m,r;scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)scanf("%d",&item[i]);
    while(r--){
        int a,b,l;scanf("%d%d%d",&a,&b,&l);
        graph[a].push_back({b,l});
        graph[b].push_back({a,l});
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dijkstra(i,n,m));
    printf("%d",ans);
    return 0;
}