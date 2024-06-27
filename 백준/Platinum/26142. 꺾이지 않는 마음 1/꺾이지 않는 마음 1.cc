#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n+1);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&v[i].first,&v[i].second);
    sort(v.begin(),v.end());
    vector<ll> dp(10001),ans(10001);
    for(int i=1;i<=n;i++){
        auto nx=dp;
        for(int x=0;x<i;x++){
            nx[x]=max(nx[x],dp[x]);
            nx[x+1]=max(nx[x+1],dp[x]+v[i].first*x+v[i].second);
        }
        dp=nx;
        for(int j=1;j<=n;j++)ans[j]=max(ans[j],dp[j]);
    }
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}