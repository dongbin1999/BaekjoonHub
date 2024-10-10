#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;scanf("%lld%lld",&n,&m);
    ll c=min(n,m+1);
    ll ones=min(n*(n-1)/2,m),twos=c*(c-1)/2-ones,ns=n*(n-1)/2-ones-twos;
    printf("%lld",ns*n+ones+twos*2<<1);
}