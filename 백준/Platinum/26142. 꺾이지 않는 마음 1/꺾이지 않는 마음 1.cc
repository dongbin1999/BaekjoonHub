#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll dp[10001][10001],ans[10001];

int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n+1);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&v[i].first,&v[i].second);
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        for(int x=0;x<i;x++){
            dp[i][x]=max(dp[i][x],dp[i-1][x]);
            dp[i][x+1]=max(dp[i][x+1],dp[i-1][x]+v[i].first*x+v[i].second);
        }
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans[j]=max(ans[j],dp[i][j]);
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}