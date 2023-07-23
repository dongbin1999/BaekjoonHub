#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,a,b,c,d,e,f,x=0;scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d,&e,&f);
    for(ll i=n/f*f+1;i<=n;i++){
        if(i%a==0)x+=i;
        if(i%b==0)x%=i;
        if(i%c==0)x&=i;
        if(i%d==0)x^=i;
        if(i%e==0)x|=i;
    }
    printf("%lld",x);
}