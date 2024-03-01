#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tup;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

char s[200001];
ll dp[2][2][200001];

void solve(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=0;i<=n;i++)for(int j=0;j<2;j++)dp[0][j][i]=dp[1][j][i]=0;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='H') {
            dp[1][1][i]=(dp[1][1][i]+dp[0][1][i-1]+dp[0][0][i-1])%mod;
            dp[0][1][i]=(dp[0][1][i]+dp[1][1][i-1])%mod;
        }
        else if(s[i]=='?'){
            dp[1][1][i]=(dp[1][1][i]+dp[0][1][i-1]+dp[0][0][i-1])%mod;
            dp[0][1][i]=(dp[0][1][i]+dp[1][1][i-1])%mod;

            dp[0][0][i]=(dp[0][0][i]+dp[0][0][i-1])%mod;
            dp[0][1][i]=(dp[0][1][i]+dp[0][1][i-1])%mod;
            dp[1][1][i]=(dp[1][1][i]+dp[1][1][i-1])%mod;
        }
        else{
            dp[0][0][i]=(dp[0][0][i]+dp[0][0][i-1])%mod;
            dp[0][1][i]=(dp[0][1][i]+dp[0][1][i-1])%mod;
            dp[1][1][i]=(dp[1][1][i]+dp[1][1][i-1])%mod;
        }
    }
    printf("%lld\n",dp[1][1][n]);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}