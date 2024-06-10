#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],dp[1001][1001];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        dp[i][j]=max({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+(abs(a[i]-b[j])<=4)});
    printf("%d",dp[n][n]);
}