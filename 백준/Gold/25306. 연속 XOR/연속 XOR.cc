#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x){
    ll ret=(x&1)^(x>>1&1);
    for(ll i=0;i<63;i++)ret+=(x>>i&1)*((~x&1)<<i);
    return ret;
}

int main(){
    ll a,b;scanf("%lld%lld",&a,&b);
    printf("%lld",f(b)^f(a-1));
    return 0;
}