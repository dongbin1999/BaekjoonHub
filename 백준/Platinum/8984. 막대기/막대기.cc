#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

unordered_map<ll,vector<pll>> up,down;
vector<pll> v;
ll l;

int dp[2][100001];

ll go(int idx,bool b){
    if(dp[b][idx]!=-1)return dp[b][idx];
    auto [x,y]=v[idx];
    ll mx=0;
    if(!b){
        for(auto [ny,nidx]:up[x])
            if(y<ny)mx=max(mx,go(nidx,!b));
    }
    else{
        for(auto [nx,nidx]:down[y])
            if(x<nx)mx=max(mx,go(nidx,!b));
    }
    return dp[b][idx]=mx+l+abs(x-y);
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;scanf("%d%lld",&n,&l);
    for(int i=0;i<n;i++){
        ll x,y;scanf("%lld%lld",&x,&y);
        v.push_back({x,y});
        up[x].push_back({y,i});
        down[y].push_back({x,i});
    }
    ll ans=0;
    for(int i=0;i<n;i++)ans=max({ans,go(i,0),go(i,1)});
    printf("%lld",ans);
    return 0;
}