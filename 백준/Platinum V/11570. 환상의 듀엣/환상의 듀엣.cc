#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2001][2001];

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[0][1]=0;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        dp[i][j+1]=min(dp[i][j+1],dp[i][j]+abs(v[j]-v[j+1]));
        dp[j][j+1]=min(dp[j][j+1],dp[i][j]+(i?abs(v[i]-v[j+1]):0));
    }
    ll ans=2e18;
    for(int i=0;i<=n;i++)ans=min(ans,dp[i][n]);
    printf("%lld",ans);
}