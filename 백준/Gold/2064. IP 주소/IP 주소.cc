#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(ll s){printf("%lld.%lld.%lld.%lld\n",s>>24&255,s>>16&255,s>>8&255,s&255);}

int main(){
    int n;scanf("%d",&n);
    ll mx=-2e18,mn=2e18;
    while(n--){
        ll a,b,c,d;scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        ll x=(a<<24)+(b<<16)+(c<<8)+d;
        mx=max(mx,x),mn=min(mn,x);
    }
    for(int i=0;i<=32;i++){
        ll all=(1ll<<i)-1;
        ll s=mn&~all,e=mn|all;
        if(s<=mn&&e>=mx){
            print(s),print(((1ll<<32)-1)^all);
            return 0;
        }
    }
}