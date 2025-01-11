#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
unordered_map<ll,ll> dp[101][1001];
unordered_map<ll,ll> go(ll n,ll k){
    if(!n) return {};
    if(!dp[k][n].empty())return dp[k][n];
    if(!k){
        unordered_map<ll,ll> ma;
        ll nn=n;
        for(ll i=2;i*i<=nn;i++)while(n%i==0)ma[i]++,n/=i;
        if(n>1)ma[n]++;
        return dp[k][nn]=ma;
    }
    auto l=go(n,k-1),r=go(n-1,k);
    for(auto [a,b]:r)l[a]=(l[a]+b)%mod;
    return dp[k][n]=l;
}


int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    ll ans=1;
    for(auto [a,b]:go(n,k))
        ans=(ans*(b+1)%mod)%mod;
    printf("%lld",ans);
}