#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][102][102];

void solve(){
    int n,a;scanf("%d%d",&n,&a);
    vector<ll> sum(n+2);
    for(int i=1;i<n;i++){
        ll x;scanf("%lld",&x);
        sum[i+1]=sum[i]+x;
    }
    memset(dp,0x3f,sizeof(dp));dp[0][a][a]=0;
    for(int len=1;len<=n;len++)for(int l=1,r=l+len-1;r<=n;l++,r++){
        dp[0][l-1][r]=min(dp[0][l-1][r],dp[0][l][r]+(sum[l]-sum[l-1])*(n-len));
        dp[1][l][r+1]=min(dp[1][l][r+1],dp[1][l][r]+(sum[r+1]-sum[r])*(n-len));
        dp[0][l-1][r]=min(dp[0][l-1][r],dp[1][l][r]+(sum[r]-sum[l-1])*(n-len));
        dp[1][l][r+1]=min(dp[1][l][r+1],dp[0][l][r]+(sum[r+1]-sum[l])*(n-len));
    }
    printf("%lld\n",min(dp[0][1][n],dp[1][1][n]));
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}