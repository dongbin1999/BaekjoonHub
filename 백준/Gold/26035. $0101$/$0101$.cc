#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    ll a,b;scanf("%lld%lld",&a,&b);
    printf("%lld",(power(2,a)+power(2,b)+mod-2)%mod);
}