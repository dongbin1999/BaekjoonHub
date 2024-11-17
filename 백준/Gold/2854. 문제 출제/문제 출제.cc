#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll a[100001],b[100001],dp[2][100001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)scanf("%lld",&b[i]);
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        dp[0][i+1]=(dp[0][i+1]+dp[0][i]*(a[i+1]+b[i]))%mod;
        dp[0][i+1]=(dp[0][i+1]+dp[1][i]*(a[i+1]+max(0ll,b[i]-1)))%mod;
        dp[1][i+1]=(dp[1][i+1]+dp[0][i]*b[i+1])%mod;
        dp[1][i+1]=(dp[1][i+1]+dp[1][i]*b[i+1])%mod;
    }
    printf("%lld",(dp[0][n]+dp[1][n])%mod);
}