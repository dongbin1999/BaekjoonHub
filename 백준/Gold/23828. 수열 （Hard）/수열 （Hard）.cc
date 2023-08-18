#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
ll dp[1002][1002];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    map<ll,ll> ma;
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        ma[x]++;
    }
    vector<pll> v;
    for(auto i:ma)v.push_back(i);
    dp[0][0]=1;
    for(int i=0;i<v.size();i++)
        for(int j=0;j<=i;j++){
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*v[i].first%mod*v[i].second%mod)%mod;
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
        }
    printf("%lld",dp[v.size()][m]);
    return 0;
}