#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    ll x;scanf("%lld",&x);
    ll ans=0;
    for(auto p:v){
        ll xx=x;
        while(xx)ans+=xx/p,xx/=p;
    }
    printf("%lld",ans);
    return 0;
}