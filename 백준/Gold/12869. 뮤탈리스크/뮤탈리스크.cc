#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%MOD;a=a*a%MOD;b/=2;}return ret;}
const int sz = 1<<17;

int dp[61][61][61];

int main()
{
    int n;
    scanf("%d",&n);
    int hp[4]={0};
    for(int i=0;i<=60;i++)
        for(int j=0;j<=60;j++)
            for(int k=0;k<=60;k++)
                dp[i][j][k]=1e9;
    for(int i=1;i<=n;i++)
        scanf("%d",&hp[i]);
    dp[hp[1]][hp[2]][hp[3]]=0;
    for(int i=hp[1];i>=0;i--)
        for(int j=hp[2];j>=0;j--)
            for(int k=hp[3];k>=0;k--)
            {
                dp[max(0,i-9)][max(0,j-3)][max(0,k-1)]=min(dp[max(0,i-9)][max(0,j-3)][max(0,k-1)],dp[i][j][k]+1);
                dp[max(0,i-9)][max(0,j-1)][max(0,k-3)]=min(dp[max(0,i-9)][max(0,j-1)][max(0,k-3)],dp[i][j][k]+1);
                dp[max(0,i-3)][max(0,j-9)][max(0,k-1)]=min(dp[max(0,i-3)][max(0,j-9)][max(0,k-1)],dp[i][j][k]+1);
                dp[max(0,i-3)][max(0,j-1)][max(0,k-9)]=min(dp[max(0,i-3)][max(0,j-1)][max(0,k-9)],dp[i][j][k]+1);
                dp[max(0,i-1)][max(0,j-9)][max(0,k-3)]=min(dp[max(0,i-1)][max(0,j-9)][max(0,k-3)],dp[i][j][k]+1);
                dp[max(0,i-1)][max(0,j-3)][max(0,k-9)]=min(dp[max(0,i-1)][max(0,j-3)][max(0,k-9)],dp[i][j][k]+1);
            }
    printf("%d",dp[0][0][0]);
    return 0;
}