#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

int main(){
    long long n;scanf("%lld",&n);
    ll x=sqrt(n),ans=2e18;
    for(ll y=max((ll)0,x-3);y<=x+3;y++){
        if(y*y>=n)ans=min(ans,y);
    }
    printf("%lld",(long long)ans);
}