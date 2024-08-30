#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
    vector<ll> v(n+1),sum(n+1),dp(n+1,2e13);
    dp[0]=0;
    for(ll i=1;i<=n;i++)scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
    for(ll i=0;i<n;i++){
        //i+1 택시로 보내기
        dp[i+1]=min(dp[i+1],dp[i]+v[i+1]*a);
        for(ll j=i+1;j<=min(n,i+40);j++){//i+1~j까지 모여서 버스로 보내기
            ll mid=(i+1+j)/2;
            ll l=(mid-(i+1)+1)*v[mid]-(sum[mid]-sum[i]);
            ll r=sum[j]-sum[mid-1]-(j-mid+1)*v[mid];
            ll add=(l+r)*a+b;
            dp[j]=min(dp[j],dp[i]+add);
        }
    }
    printf("%lld",dp[n]);
}