#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
char a[1001],b[1001];
int main(){
    scanf("%s%s",a,b);
    memset(dp,0x3f,sizeof(dp));
    int n=strlen(a),m=strlen(b),mx=max(n,m),ans=1e9;
    dp[0][0]=0;
    for(int i=0;i<=mx;i++)for(int j=0;j<=mx;j++){
        if(i>=n&&j>=m)ans=min(ans,dp[i][j]);
        //match
        if(a[i]==b[j])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
        //delete a
        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
        //insert a
        dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
        //replace a
        dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
    }
    printf("%d",ans);
}