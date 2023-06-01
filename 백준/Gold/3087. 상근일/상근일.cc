#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    if(k>=n)printf("%lld",n*2-1);
    else printf("%lld",(n*n-1)/k+k);
    return 0;
}