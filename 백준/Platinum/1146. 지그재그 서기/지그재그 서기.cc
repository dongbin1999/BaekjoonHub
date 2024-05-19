#include<bits/stdc++.h>
using namespace std;
const int mod=1e6;
int dp[2][101][101];//지금 오름/내림이고, 남아있는 나보다 작은 수가 x개, 큰 수가 y개일때, 경우의수

int main(){
    int n;scanf("%d",&n);
    if(n==1)return !printf("1");
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i==j)continue;
        if(i<j)dp[0][j-2][n-j]++;
        else dp[1][j-1][n-j-1]++;
    }
    for(int len=2;len<n;len++)for(int s=0,l=n-s-len;l>=0;s++,l--){
        for(int i=1;i<=l;i++)dp[0][s+l-i][i-1]=(dp[0][s+l-i][i-1]+dp[1][s][l])%mod;
        for(int i=1;i<=s;i++)dp[1][i-1][s+l-i]=(dp[1][i-1][s+l-i]+dp[0][s][l])%mod;
    }
    printf("%d",(dp[0][0][0]+dp[1][0][0])%mod);
}