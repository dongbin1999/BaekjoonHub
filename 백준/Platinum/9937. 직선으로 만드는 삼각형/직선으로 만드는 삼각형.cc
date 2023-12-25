#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    ll n;scanf("%lld",&n);
    map<pll,ll> ma;
    for(ll i=1;i<=n;i++){
       ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
       ll gcd=GCD(a,b);
       ma[{a/gcd,b/gcd}]++;
    }
    ll ans=0;
    for(auto [a,b]:ma){
        ans+=((n-b)*(n-b-1)/2%mod)*b%mod,ans%=mod;
        ans+=mod-(n-b)*(b*(b-1)/2%mod)%mod,ans%=mod;
    }
    printf("%lld",ans*power(3ll,mod-2ll)%mod);
    return 0;
}