#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;scanf("%lld%lld",&n,&k);
    ll ans=63ll-__builtin_clzll(n+1),lead=(1ll<<k)-1;
    for(ll i=1;i<63-k;i++)
        ans+=min((1ll<<i)-1,max(n-(lead<<i)+1,0ll));
    printf("%lld",ans);
    return 0;
}