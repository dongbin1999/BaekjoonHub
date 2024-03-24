#include <bits/stdc++.h>
using namespace std;

int dp[2001][1001],s[1001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    int a,d;scanf("%d%d",&a,&d);
    for(int i=0;i<n;i++)for(int j=0;j<=i;j++){
        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+s[i+1]);
        dp[i+d][j+1]=max(dp[i+d][j+1],dp[i][j]+a);
    }
    int ans=1e9;
    for(int i=1;i<=n+n;i++)for(int j=0;j<=n;j++)if(dp[i][j]>=m)ans=min(ans,j);
    printf("%d",ans==1e9?-1:ans);
    return 0;
}