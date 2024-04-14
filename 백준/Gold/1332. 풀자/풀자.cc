#include<bits/stdc++.h>
using namespace std;
int dp[55][51][51];
int main(){
    int n,v;scanf("%d%d",&n,&v);
    memset(dp,0x3f,sizeof(dp));
    vector<int> a(n);for(int i=0;i<n;i++)scanf("%d",&a[i]);
    dp[0][0][0]=1;
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(k+1<n)dp[k+1][a[i]<a[k+1]?i:k+1][a[j]>a[k+1]?j:k+1]=min(dp[k+1][a[i]<a[k+1]?i:k+1][a[j]>a[k+1]?j:k+1],dp[k][i][j]+1);
        if(k+2<n)dp[k+2][a[i]<a[k+2]?i:k+2][a[j]>a[k+2]?j:k+2]=min(dp[k+2][a[i]<a[k+2]?i:k+2][a[j]>a[k+2]?j:k+2],dp[k][i][j]+1);
    }

    int ans=n;
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        if(a[i]+v<=a[j])ans=min(ans,dp[k][i][j]);
    printf("%d",ans);
}