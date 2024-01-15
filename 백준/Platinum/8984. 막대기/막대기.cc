#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,bool> tup;

unordered_map<ll,vector<ll>> up,down;
ll l;

map<tup,ll> dp;

ll go(ll x,ll y,bool b){
    if(dp[{x,y,b}])return dp[{x,y,b}];
    ll mx=0;
    if(!b){
        for(auto ny:up[x])
            if(y<ny)mx=max(mx,go(x,ny,!b));
    }
    else{
        for(auto nx:down[y])
            if(x<nx)mx=max(mx,go(nx,y,!b));
    }
    return dp[{x,y,b}]=mx+l+abs(x-y);
}

int main(){
    int n;scanf("%d%lld",&n,&l);
    vector<pll> v(n);
    sort(v.begin(),v.end());
    for(auto &[x,y]:v){
        scanf("%lld%lld",&x,&y);
        up[x].push_back(y);
        down[y].push_back(x);
    }
    ll ans=0;
    for(auto [x,y]:v)
        ans=max({ans,go(x,y,0),go(x,y,1)});
    printf("%lld",ans);
    return 0;
}