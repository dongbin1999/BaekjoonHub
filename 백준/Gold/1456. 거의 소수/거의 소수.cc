#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool no_prime[10000001];

int main() {
	ll a,b;scanf("%lld%lld",&a,&b);
	ll ans=0;
	for(ll i=2;i*i<=b;i++){
		if(no_prime[i])continue;
		for(ll j=i*i;j<=1e7;j+=i)
			no_prime[j]=1;
	}
	for(ll i=2;i*i<=b;i++){
		if(no_prime[i])continue;
		ll d=i*i;
		while(1){
			if(d>=a)ans++;
			if((b/d)/i==0)break;
			d*=i;
		}
	}
	printf("%lld",ans);
	return 0;
}