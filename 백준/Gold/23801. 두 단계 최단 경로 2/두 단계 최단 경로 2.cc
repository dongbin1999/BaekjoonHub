#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> graph[100001];
vector<ll> dijkstra(int s,int n){
    vector<ll> d(n+1,2e18);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<=dist)continue;d[cur]=dist;
        for(auto [nx,cost]:graph[cur])
            pq.push({dist+cost,nx});
    }
    return d;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        graph[u].push_back({v,w}),graph[v].push_back({u,w});
    }
    int x,z,p;scanf("%d%d%d",&x,&z,&p);
    auto a=dijkstra(x,n),b=dijkstra(z,n);
    ll ans=2e18;
    while(p--){
        int y;scanf("%d",&y);
        ans=min(ans,a[y]+b[y]);
    }
    printf("%lld",ans>1e18?-1:ans);
    return 0;
}