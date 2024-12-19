#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a,ll n){
    ll ret=0;
    for(ll x=2;x<=a;x++){
        ll d=1;
        for(ll i=0;i<n;i++){d*=x;if(d>a){d=-1;break;}}
        if(d==-1)ret+=a/x;
        else ret+=a/x-a/d;
    }
    return ret;
}

int main(){
    ll a,b,n;scanf("%lld%lld%lld",&a,&b,&n);
    printf("%lld",f(a+b,n)-f(a-1,n)-b-(a!=1));
}