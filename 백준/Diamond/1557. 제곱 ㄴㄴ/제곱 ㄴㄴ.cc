#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=60000;

int main(){
	vector<bool> no_prime(sz+1,false);
	vector<ll> sq;
	no_prime[0]=no_prime[1]=1;
    for(int i=2;i<=sz;i++)
        if(!no_prime[i]){
            sq.push_back(i*i);
            for(int j=i*2;j<=sz;j+=i)
                no_prime[j]=true;
        }
	
	ll k;scanf("%lld",&k);
	ll l=1,r=3600000000ll,mid,ans=r;
	while(l<=r){
		mid=(l+r)/2;
		ll x=0;
		for(int i=2;i*i<=mid;i++){
			if(!no_prime[i]){
				x+=mid/(i*i);
				continue;
			}
			bool b=false;ll ii=i,c=0;
			for(int j=2;j*j<=i;j++){
				if(no_prime[j]) continue;
				ll temp=0;
				if(ii%j==0)c++;
				while(ii%j==0)temp++,ii/=j,b|=temp>1;
			}
			if(ii>1)c++;
			if(!b)c%2?x+=mid/(i*i):x-=mid/(i*i);
		}
		if(mid-x>=k)ans=min(ans,mid),r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
    return 0;
}