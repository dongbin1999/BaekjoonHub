#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans1(ll x){
    vector<ll> v;
    for(ll i=1;i<=x;i++)if(__gcd(x,i)==1)v.push_back(i);
    return v[(v.size()-1)/2];
}
ll ans2(ll x){
    ll ans=x/2;
    while(ans>1&&__gcd(x,ans)>1)ans--;
    return ans;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll x;scanf("%lld",&x);
        //assert(ans1(x)==ans2(x));
        printf("%lld\n",ans2(x));
    }
}