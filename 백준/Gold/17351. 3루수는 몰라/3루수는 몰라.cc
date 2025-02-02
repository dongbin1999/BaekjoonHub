#include <bits/stdc++.h>
using namespace std;

char s[501][502];
string a="MOLA";
int dp[4][502][502];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    memset(dp,-0x3f,sizeof(dp));
    dp[0][1][1]=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        for(int x=0;x<4;x++){
            dp[s[i][j]==a[x]?(x+1)%4:0][i+1][j]=max(dp[s[i][j]==a[x]?(x+1)%4:0][i+1][j],
            dp[x][i][j]+(x==3&&s[i][j]==a[x]));
            dp[0][i+1][j]=max(dp[0][i+1][j],dp[x][i][j]);
            dp[s[i][j]==a[x]?(x+1)%4:0][i][j+1]=max(dp[s[i][j]==a[x]?(x+1)%4:0][i][j+1],
            dp[x][i][j]+(x==3&&s[i][j]==a[x]));
            dp[0][i][j+1]=max(dp[0][i][j+1],dp[x][i][j]);
        }
    printf("%d",dp[0][n][n+1]);
    return 0;
}