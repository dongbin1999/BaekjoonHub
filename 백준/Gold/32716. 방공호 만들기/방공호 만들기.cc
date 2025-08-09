#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;scanf("%lld",&n);
    ll x=n/4,y=n%4;
    if(n<4)return !printf("0");
    ll ans=x*x+(x-1)*(x-1);
    if(n<6)return !printf("%lld",ans);
    if(y==1)ans+=x-1;
    if(y==2)ans+=x*2-1;
    if(y==3)ans+=x*3-1;
    printf("%lld",ans);
}