#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;

ll dp[200001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pil> v(m);
    for(auto &[l,s]:v)scanf("%d%lld",&l,&s);
    for(int i=1;i<=n;i++){
        ll mx=2e18;
        for(auto [l,s]:v)
            mx=min(mx,dp[max(0,i-l)]+s);
        dp[i]=mx;
        printf("%lld\n",dp[i]);
    }
    return 0;
}