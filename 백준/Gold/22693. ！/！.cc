#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll x,string y){
    ll z=0;
    for(auto i:y)z=z*x+(i-(isupper(i)?'A'-10:'0'));
    vector<ll> v={2,3,5,7,11,13,17,19,23,29,31},cnt(32,0);
    for(auto p:v){
        ll zz=z;
        while(zz>0)cnt[p]+=zz/p,zz/=p;
    }
    ll ans=2e18;
    for(auto p:v)
        if(x%p==0){
            ll t=0;while(x%p==0)x/=p,t++;
            ans=min(ans,cnt[p]/t);
        }
    printf("%lld\n",ans);
}

int main(){
    ll x;string y;
    while(1){
        cin>>x>>y;
        if(!x)break;
        solve(x,y);
    }
    return 0;
}