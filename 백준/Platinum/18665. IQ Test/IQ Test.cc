#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

set<ll> se={0,1,2};
vector<pll> ans;

pll p(ll x){
    ll r=sqrt(x);
    if(r*r<x)r++;
    return {r,r*r-x};
}

void go(pll n){
    auto [x,y]=n;
    if(se.count(x*x-y))return;
    if(!se.count(x))go(p(x));
    if(!se.count(y))go(p(y));
    ans.push_back({x,y});
    se.insert(x*x-y);
    assert(se.size()<=46);
}

int main(){
    ll n;scanf("%lld",&n);
    go(p(n));
    for(auto [x,y]:ans)printf("%lld %lld\n",x,y);
}