#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;scanf("%lld",&x);
    ll ans=x&((1<<16)-1);
    for(int i=16;i<32;i++)
        if(x>>i&1)ans+=1ll<<(31-i);
    if(x>>16)ans++;
    printf("%lld",ans);
}