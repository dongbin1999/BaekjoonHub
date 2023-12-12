#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,y;scanf("%lld.%lld",&x,&y);
    x=x*10000+y*10;
    for(ll i=1;i<=100000;i++){
        ll a=x*i/1000000;
        ll z=a*1000000/i;
        z+=(z%10>=5?10:0)-z%10;
        if(x==z){printf("%lld\n",i);return;}
        a++;
        z=a*1000000/i;
        z+=(z%10>=5?10:0)-z%10;
        if(x==z){printf("%lld\n",i);return;}
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}