#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k,n;scanf("%lld%lld",&k,&n);
    ll x=1;
    while(n--){
        ll y;scanf("%lld",&y);
        x=lcm(x,y);
    }
    printf("%lld",x-k);
}