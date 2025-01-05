#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    while(n--){
        ll a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ll mx=0;
        mx=max(mx,(a+d)*(a+d)+b*b+c*c+7ll*min({a+d,b,c}));
        mx=max(mx,(b+d)*(b+d)+a*a+c*c+7ll*min({b+d,a,c}));
        mx=max(mx,(c+d)*(c+d)+b*b+a*a+7ll*min({c+d,b,a}));
        if(d<10){
            for(ll x=0;x<=d;x++)for(ll y=0;x+y<=d;y++){
                ll z=d-x-y;
                mx=max(mx,(a+x)*(a+x)+(b+y)*(b+y)+(c+z)*(c+z)+7ll*min({a+x,b+y,c+z}));
            }
        }
        printf("%lld\n",mx);
    }
}