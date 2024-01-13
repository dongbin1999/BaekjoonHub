#include <bits/stdc++.h>
using namespace std;

int a[101][101],dp[101][101];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),dp[i][j]=1;
    int ans=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        for(int ni=i;ni<=n;ni++)for(int nj=j;nj<=n;nj++)
            if(a[i][j]<a[ni][nj])dp[ni][nj]=max(dp[ni][nj],dp[i][j]+1),ans=max(ans,dp[ni][nj]);
    printf("%d",ans);
}
