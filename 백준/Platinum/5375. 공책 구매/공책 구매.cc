#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,3> tup;

void solve(){
    ll n,m;scanf("%lld%lld",&n,&m);
    vector<tup> v(m);
    for(auto &[s,p,o]:v)scanf("%lld%lld%lld",&s,&p,&o);
    sort(v.begin(),v.end(),[](tup a,tup b){return a[1]<b[1];});
    vector<ll> dp(n+1,2e18);dp[0]=0;
    for(auto [s,p,o]:v){
        auto nx=dp;
        for(int i=0;i<n;i++){
            ll buy=min(s,n-i);
            nx[i+buy]=min(nx[i+buy],dp[i]+o+buy*p);
        }
        dp=nx;
    }
    printf("%lld\n",dp[n]);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}