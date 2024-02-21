#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;scanf("%lld",&n);
    ll ans=0,mi=9;
    while(n>0){
        ans+=n;
        n-=mi,mi*=10;
    }
    printf("%lld",ans);
    return 0;
}