#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tup;

vector<pll> graph[50001];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        ll x,y,c;scanf("%lld%lld%lld",&x,&y,&c);
        graph[x].push_back({y,c});
        graph[y].push_back({x,c});
    }
    int s,e;scanf("%d%d",&s,&e);
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,0,s});
    map<pll,ll> dist;
    while(!pq.empty()){
        auto [d,mx,node]=pq.top();pq.pop();
        if(node==e)return !printf("%lld",d);
        if(dist.find({node,mx})!=dist.end())continue;
        dist[{node,mx}]=d;
        for(auto [nx,cost]:graph[node])
            if(cost>mx)pq.push({d+cost,cost,nx});
    }
    printf("DIGESTA");
    return 0;
}