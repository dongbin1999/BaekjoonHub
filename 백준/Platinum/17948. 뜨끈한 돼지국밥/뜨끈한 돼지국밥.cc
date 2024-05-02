#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pll dp[5001];
ll sum[5002],cost[5001][5001];
int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
    ll c,m;scanf("%lld%lld",&c,&m);
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
    for(int l=1;l<=n;l++)for(int r=l;r<=n;r++){
        int mid=l+r>>1;
        cost[l][r]=sum[r]-sum[mid]-v[mid]*(r-mid);
        cost[l][r]+=v[mid]*(mid-l+1)-(sum[mid]-sum[l-1]);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]={0,0};
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
        dp[i]=min(dp[i],{dp[i-j].first+cost[i-j+1][i]*c+m,dp[i-j].second+1});
    printf("%lld %lld",dp[n].first,dp[n].second);
}