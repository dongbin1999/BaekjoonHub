#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll> v={1ll<<60,0,0,0},t;
    ll k,a,s,r,d;scanf("%lld",&k);
    for(ll h=1;h<1001999;h++){
        a=(k+h-1)/h,s=ceil(sqrt(a)),r=s*s-a,d=sqrt(r);
        t={h*s*2+s*s-d*d,h,s-d,s+d};
        sort(t.end()-3,t.end());v=min(v,t);
    }
    printf("%lld %lld %lld",v[1],v[2],v[3]);
}