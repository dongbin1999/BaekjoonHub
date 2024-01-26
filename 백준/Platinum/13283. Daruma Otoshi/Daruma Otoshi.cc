#include <bits/stdc++.h>
using namespace std;

int dp[301][301];

int main() {
    while(1){
        int n;scanf("%d",&n);
        if(!n)break;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        for(int len=2;len<=n;len++)for(int l=1,r=l+len-1;r<=n;l++,r++){
            if(dp[l+1][r-1]==len-2&&abs(v[l]-v[r])<2)dp[l][r]=max(dp[l][r],dp[l+1][r-1]+2);
            if(abs(v[l]-v[l+1])<2)dp[l][r]=max(dp[l][r],dp[l+2][r]+2);
            if(abs(v[r]-v[r-1])<2)dp[l][r]=max(dp[l][r],dp[l][r-2]+2);
            for(int m=l;m<r;m++)dp[l][r]=max(dp[l][r],dp[l][m]+dp[m+1][r]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)ans=max(ans,dp[i][j]);
        printf("%d\n",ans);
    }
}