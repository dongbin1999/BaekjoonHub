#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tup;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

vector<pll> graph[200001];
ll dist[200001],dist2[200001];

int main(){
    int n,m,s,e;scanf("%d%d%d%d",&n,&m,&s,&e);
    fill(dist,dist+1+n,2e18);
    while(m--){
        ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        graph[a].push_back({b,c}),graph[b].push_back({a,c});
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,cur]=pq.top();pq.pop();
        if(dist[cur]<1e18)continue;
        dist[cur]=d;
        for(auto [nx,cost]:graph[cur])
            pq.push({d+cost,nx});
    }

    vector<ll> v;
    pq.push({0,e});
    fill(dist2,dist2+1+n,2e18);
    while(!pq.empty()){
        auto [d,cur]=pq.top();pq.pop();
        if(dist2[cur]<1e18)continue;
        dist2[cur]=d;
        if(dist2[cur]+dist[cur]==dist[e])v.push_back(cur);
        for(auto [nx,cost]:graph[cur])
            pq.push({d+cost,nx});
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(auto i:v)printf("%lld ",i);
    return 0;
}