#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

void solve(){
	ll r,g,b,k;scanf("%lld %lld %lld %lld",&r,&g,&b,&k);
	ll x,y,t;
	t=power(b+1,k);
	y=t*b%mod;
	x=t*(((g+b)*k+r*b)%mod)%mod;
	t=power(b,k+1)*r%mod;
	x=(x+mod-t)%mod;
	printf("%lld\n",x*power(y,mod-2)%mod);
	return;
}

int main() {
	ll t;scanf("%lld ",&t);
	while(t--)solve();
	return 0;
}