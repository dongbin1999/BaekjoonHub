#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    ll n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
    if(k==1||n<k)return !printf("%lld",power(m,n));
    if(n>k)return !printf("%lld",power(m,k%2+1));
    return !printf("%lld",power(m,(n+1)/2));
}