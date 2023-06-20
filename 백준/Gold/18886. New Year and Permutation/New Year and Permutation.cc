#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll fac[250001]={1,1};
int main(){
    ll n;scanf("%lld %lld",&n,&mod);
    for(ll i=2;i<=n;i++)fac[i]=(fac[i-1]*i)%mod;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll t=(n-i+1)*(n-i+1)%mod*fac[n-i]%mod*fac[i]%mod;
        ans=(ans+t)%mod;
    }
    printf("%lld",ans);
    return 0;
}