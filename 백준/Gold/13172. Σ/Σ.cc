#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    ll m;scanf("%lld",&m);
    ll x=1,sum=0;
    vector<pll> v(m);
    for(auto &[n,s]:v)scanf("%lld %lld",&n,&s),x=(x*n)%mod;
    for(auto &[n,s]:v){
        ll d=x*power(n,mod-2)%mod;
        sum+=d*s%mod,sum%=mod;
    }
    printf("%lld",sum*power(x,mod-2)%mod);
    return 0;
}