#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[200001][11];

int main(){
    memset(dp,-0x3f,sizeof(dp));
    dp[0][10]=0;
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    for(int i=0;i<n;i++)for(int pre=1;pre<=10;pre++)for(int len=1;len<10;len++){
        if(pre==len||i+len-1>=n)continue;
        ll add=0;
        for(int j=i;j<i+len;j++)add^=v[j];
        dp[i+len][len]=max(dp[i+len][len],dp[i][pre]+add);
    }
    ll ans=0;
    for(int i=1;i<10;i++)ans=max(ans,dp[n][i]);
    printf("%lld",ans);
}