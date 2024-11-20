#include<bits/stdc++.h>
using namespace std;
int a[10],dp[5001][5001];

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-2e9;
    dp[0][0]=0;
    for(int i=0;i<n;i++)for(int sum=0;sum<=i;sum++)for(int j=0;j<m;j++){
        if(dp[i][sum]<-1e9)continue;
        int x=i+sum+a[j],y=sum+a[j];
        if(x<=n)dp[x][y]=max(dp[x][y],dp[i][sum]+a[j]);
    }

    int ans=-1;
    for(int i=0;i<=n;i++)ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}