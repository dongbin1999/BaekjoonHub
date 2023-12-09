#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        k-=x;
    }
    k++;
    ll ans=1;
    for(int i=k;i<k+n;i++)ans=(ans*i)%mod;
    printf("%lld",ans);
    return 0;
}