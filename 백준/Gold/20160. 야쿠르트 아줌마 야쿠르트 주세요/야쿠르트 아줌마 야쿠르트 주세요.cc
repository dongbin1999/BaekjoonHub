#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> graph[10001];
ll d[10001],D[10001];

void dijkstra(int s,ll t){
    memset(D,0x3f,sizeof(D));
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({t,s});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(D[cur]<dist)continue;D[cur]=dist;
        for(auto [nx,cost]:graph[cur])pq.push({dist+cost,nx});
    }
}

int main(){
    int n,e;scanf("%d%d",&n,&e);
    memset(d,0x3f,sizeof(d));
    while(e--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        graph[u].push_back({v,w}),graph[v].push_back({u,w});
    }
    vector<int> ya(10);
    for(auto &x:ya)scanf("%d",&x);
    int s;scanf("%d",&s);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<dist)continue;d[cur]=dist;
        for(auto [nx,cost]:graph[cur])pq.push({dist+cost,nx});
    }
    ll ans=1e9,t=0,cur=0;
    while(1){
        if(d[ya[cur]]<=t)ans=min(ans,(ll)ya[cur]);
        dijkstra(ya[cur],t);
        int nx=cur+1;
        while(nx<10&&D[ya[nx]]>1e18)nx++;
        if(nx==10)break;
        t=D[ya[nx]],cur=nx;
    }
    printf("%lld",ans==1e9?-1:ans);
    return 0;
}