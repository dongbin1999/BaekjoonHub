#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    int n;ll l;scanf("%d%lld",&n,&l);
    vector<pll> v;
    ll ans=0;
    while(n--){
        ll x,y;scanf("%lld%lld",&x,&y);
        if(y>5)v.push_back({x,y});
        ans+=y;
    }
    sort(v.begin(),v.end(),greater<pll>());
    for(auto [x,y]:v){
        ll z=-min(0ll,l-x*y);
        ans+=z,l=l+z-x*(y-5);
    }
    printf("%lld",ans);
    return 0;
}