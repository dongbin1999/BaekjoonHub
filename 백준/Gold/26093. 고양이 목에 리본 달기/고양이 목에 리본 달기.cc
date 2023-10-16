#include <bits/stdc++.h>
using namespace std;
int dp[101][10001],l[10002],r[10002],x[10002];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int j=1;j<=k;j++)scanf("%d",&x[j]);
        for(int j=1;j<=k;j++)l[j]=max(l[j-1],dp[i-1][j]);
        for(int j=k;j>=1;j--)r[j]=max(r[j+1],dp[i-1][j]);
        for(int j=1;j<=k;j++)dp[i][j]=max(l[j-1],r[j+1])+x[j];
    }
    printf("%d",*max_element(dp[n]+1,dp[n]+1+k));
    return 0;
}