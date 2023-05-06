#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;scanf("%lld",&n);
	ll r=sqrt(n);
	for(ll x=2;x<=r;x++){
		ll sum=1+x,num=x*x,d=2;
		while(num<=n){
			sum+=num;
			if(n%sum==0){
				printf("%lld\n",d+1);
				for(ll a=1,i=0;i<=d;i++){
					printf("%lld ",a*(n/sum));
					a*=x;
				}
				return 0;
			}
			num*=x,d++;
		}
	}
	printf("-1");
	return 0;
}