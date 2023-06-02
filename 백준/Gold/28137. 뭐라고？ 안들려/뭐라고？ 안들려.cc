#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> ma;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    while(n--){
        ll x,y;scanf("%lld%lld",&x,&y);
        ma[x*k-y]++;
    }
    ll ans=0;
    for(auto [x,y]:ma)ans+=y*(y-1)/2;
    printf("%lld",ans*2);
    return 0;
}