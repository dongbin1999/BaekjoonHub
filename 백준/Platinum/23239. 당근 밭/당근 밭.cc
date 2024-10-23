#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll w,h,l;scanf("%lld%lld%lld",&w,&h,&l);
    ll ans=0;
    for(ll x=-l;x<=l;x++){
        ll mn=sqrt(l*l-x*x),mx=-1;mn*=-1;
        if(x<=0)mx=sqrt(l*l-x*x);
        else{
            if(x>=w)mx=max(mx,(ll)sqrt((l-w)*(l-w)-(x-w)*(x-w)));
            if(x<=l-h)mx=max(mx,h+(ll)sqrt((l-h)*(l-h)-x*x));
        }
        ll add=mx-mn+1;
        if(x>=0&&x<=w)add-=min(mx+1,h+1);
        ans+=max(0ll,add);
    }
    printf("%lld",ans);
    return 0;
}