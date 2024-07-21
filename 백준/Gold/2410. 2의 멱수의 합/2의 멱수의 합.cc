#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9;
ll dp[1000001];
ll go(ll x){
    if(x<=2)return x;
    if(dp[x]>0)return dp[x];
    if(x%2) return dp[x]=go(x-1);
    else return dp[x]=(go(x-2)+go(x/2))%mod;
}

int main() {
    ll n;scanf("%lld",&n);
    printf("%lld",go(n));
}