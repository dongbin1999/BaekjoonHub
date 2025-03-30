#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll s,x,m,d,k;scanf("%lld%lld%lld%lld%lld",&s,&x,&m,&d,&k);
    ll g=__gcd(x,m);
    s%=g;ll mx=m-g+s;
    if(!mx)return !printf("0");
    ll ok=k/mx;
    if(!ok)printf("0");
    else printf("%lld",(d-1)/ok);
    return 0;
}