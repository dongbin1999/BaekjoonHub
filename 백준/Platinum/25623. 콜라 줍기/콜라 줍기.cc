#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kipa[402][402];
ll kyaryunha[402][402];
ll dp[402][402][402];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&kipa[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&kyaryunha[i][j]);
    memset(dp,-0x3f,sizeof(dp)),dp[1][2][1]=kipa[1][2]+kyaryunha[2][1];
    for(int i=1;i<=n;i++)for(int j=2;j<=n;j++)for(int k=1;k<j;k++){
        int ni=i+1,nj=j,nk=k;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kipa[ni][nj]+kyaryunha[min(n+1,ni+nj-nk)][nk]);
        ni=i,nj=j+1,nk=k;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kipa[ni][nj]+kyaryunha[min(n+1,ni+nj-nk)][nk]);
        ni=i+1,nj=j,nk=k+1;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kipa[ni][nj]+kyaryunha[min(n+1,ni+nj-nk)][nk]);
        ni=i,nj=j+1,nk=k+1;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kipa[ni][nj]+kyaryunha[min(n+1,ni+nj-nk)][nk]);
    }
    ll ans=dp[n][n][n];
    memset(dp,-0x3f,sizeof(dp)),dp[1][2][1]=kyaryunha[1][2]+kipa[2][1];
    for(int i=1;i<=n;i++)for(int j=2;j<=n;j++)for(int k=1;k<j;k++){
        int ni=i+1,nj=j,nk=k;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kyaryunha[ni][nj]+kipa[min(n+1,ni+nj-nk)][nk]);
        ni=i,nj=j+1,nk=k;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kyaryunha[ni][nj]+kipa[min(n+1,ni+nj-nk)][nk]);
        ni=i+1,nj=j,nk=k+1;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kyaryunha[ni][nj]+kipa[min(n+1,ni+nj-nk)][nk]);
        ni=i,nj=j+1,nk=k+1;
        if(nj>nk||(ni==n&&nj==n&&nk==n))
            dp[ni][nj][nk]=max(dp[ni][nj][nk],dp[i][j][k]+kyaryunha[ni][nj]+kipa[min(n+1,ni+nj-nk)][nk]);
    }
    ans=max(ans,dp[n][n][n]);
    printf("%lld",ans);
}