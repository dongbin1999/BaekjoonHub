#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll dp[5002][5002];

int main(){
   int n;scanf("%d",&n);
   vector<pll> v(n+1);
   ll ans=0;
   for(int i=1;i<=n;i++)scanf("%lld",&v[i].second);
   for(int i=1;i<=n;i++)scanf("%lld",&v[i].first);
   sort(v.begin(),v.end());
   memset(dp,-0x3f,sizeof(dp));
   for(int i=0;i<=n;i++)dp[0][i]=0,swap(v[i].first,v[i].second);
   for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
       ans=max(ans,dp[i][j]);
       dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
       if(j)dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+v[i+1].first-v[i+1].second*(j-1));
   }
   printf("%lld",ans);
}