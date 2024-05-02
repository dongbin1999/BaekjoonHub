#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pll dp[5001];
ll sum[5002],v[5001];
ll cost(int l,int r){
    int mid=l+r>>1;
    return sum[r]-sum[mid]-v[mid]*(r-mid)+v[mid]*(mid-l+1)-(sum[mid]-sum[l-1]);
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
    ll c,m;scanf("%lld%lld",&c,&m);
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0]={0,0};
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
        dp[i]=min(dp[i],{dp[i-j].first+cost(i-j+1,i)*c+m,dp[i-j].second+1});
    printf("%lld %lld",dp[n].first,dp[n].second);
}