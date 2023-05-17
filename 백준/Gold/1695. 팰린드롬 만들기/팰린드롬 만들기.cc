#include <bits/stdc++.h>
using namespace std;

int dp[5002][5002],a[5002];

int main() {
    memset(dp,0x3f,sizeof(dp));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp[i][i]=0;
    for(int i=1;i<n;i++)dp[i][i+1]=a[i]!=a[i+1];
    for(int len=1;len<=n;len++)for(int l=1,r=l+len-1;r<=n;l++,r++){
            dp[l][r]=min(dp[l+1][r-1]+(a[l]!=a[r])*2,dp[l][r]);
            dp[l][r]=min(dp[l+1][r]+1,dp[l][r]);
            dp[l][r]=min(dp[l][r-1]+1,dp[l][r]);
    }
    printf("%d",dp[1][n]);
    return 0;
}