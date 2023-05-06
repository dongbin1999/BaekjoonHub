#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll n, vector<ll> v){
	ll x=1;
	for(auto i:v){x*=i;if(x>=n) return true;}
	return x>=n;
}

int main() {
	ll n,p,v;scanf("%lld %lld %lld",&n,&p,&v);
	ll ans=n*p+v;
	for(ll x=2;x<=35;x++){
		ll l=x,r=((ll)sqrt(n)+1)*2,mid,temp=2e15;
		while(l<=r){
			mid=(l+r)/2;
			vector<ll> vv(x,0);
			for(ll i=0;i<x;i++)vv[i]+=mid/x;
			for(ll i=0;i<mid%x;i++)vv[i]++;
			if(check(n,vv))temp=min(temp,mid),r=mid-1;
			else l=mid+1;
		}
		ans=min(ans,temp*p+x*v);
	}
	printf("%lld",ans);
	return 0;
}