#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int nx[2][105];
char s[105];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    int p[2]={n+1,n+1};
    for(int i=n;i>=0;i--){
        nx[0][i]=p[0],nx[1][i]=p[1];
        if(s[i]=='(')p[0]=i;
        else if(s[i]==')')p[1]=i;
    }

    vector<vector<ll>> dp(n+2,vector<ll>(n+2)),init=dp;
    dp[0][0]=1;
    ll ans=0;
    for(int len=0;len<n;len++){
        vector<vector<ll>> tmp=init;
        for(int i=0;i<n;i++)for(int val=0;val<=len;val++){
            tmp[nx[0][i]][val+1]=(tmp[nx[0][i]][val+1]+dp[i][val])%mod;
            if(val)tmp[nx[1][i]][val-1]=(tmp[nx[1][i]][val-1]+dp[i][val])%mod;
        }
        dp=tmp;
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)printf("len=%d,dp[%d][%d]=%lld\n",len,i,j,dp[i][j]);
        if(len%2)for(int i=1;i<=n;i++)ans=(ans+dp[i][0])%mod;
    }
    printf("%lld",ans);
}