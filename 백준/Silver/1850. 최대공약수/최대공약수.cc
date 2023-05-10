#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}

int main(){
    ll a,b;scanf("%lld%lld",&a,&b);
    ll x=GCD(a,b);
    while(x--)printf("1");
    return 0;
}