#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pll> v(n);
    for(auto &[x,y]:v)scanf("%lld%lld",&x,&y);
    sort(v.begin(),v.end());
    ll ans=0,pre=0;
    for(auto [x,y]:v)ans+=max(0ll,y-pre),pre=y;
    printf("%lld",ans);
    return 0;
}