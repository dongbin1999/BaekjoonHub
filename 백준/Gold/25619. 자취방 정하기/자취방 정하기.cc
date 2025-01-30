#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> graph[200001];

int main(){
    vector<int> ans;
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        ll a,b,x,y;scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        graph[a].push_back({b,x+y}),graph[b].push_back({a,x+y});
    }
    bool ok=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> d(n+1,2e18);
    pq.push({0,1});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(dist>=d[cur])continue;
        d[cur]=dist;
        for(auto [nx,cost]:graph[cur]){
            if(cost<0)ok=1,cost=0;
            pq.push({dist+cost,nx});
        }
    }
    ll t;scanf("%lld",&t);
    if(ok)t=2e17;
    for(int i=2;i<=n;i++)if(d[i]<=t*2)ans.push_back(i);
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}