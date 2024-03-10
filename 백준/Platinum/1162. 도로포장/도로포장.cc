#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef array<ll,3> tup;

vector<pll> graph[10001];
ll dp[21][10001];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    while(m--){
        ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    memset(dp,0x3f,sizeof(dp));
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,k,1});
    while(!pq.empty()){
        auto [d,pass,cur]=pq.top();pq.pop();
        if(dp[pass][cur]<1e18)continue;
        dp[pass][cur]=d;
        for(auto [nx,cost]:graph[cur]){
            if(pass)pq.push({d,pass-1,nx});
            pq.push({d+cost,pass,nx});
        }
    }
    ll ans=1e18;
    for(int i=0;i<=k;i++)ans=min(ans,dp[i][n]);
    printf("%lld",ans);
    return 0;
}