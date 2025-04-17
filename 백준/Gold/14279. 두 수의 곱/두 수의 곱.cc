#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
    ll ans=LLONG_MAX;
    for(ll A=max(1ll,a-2000000);A<=a+2000000;A++){
        ll aa=abs(a-A);
        ll B=1,bb=abs(b-B),C=A*B,cc=abs(c-C);
        while(aa+C-c<=2000000){
            ans=min(ans,aa+bb+cc);
            B++,bb=abs(b-B),C=A*B,cc=abs(c-C);
        }
    }
    printf("%lld",ans);
}