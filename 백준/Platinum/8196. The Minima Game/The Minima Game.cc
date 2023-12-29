#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n,0);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    UNIQUE(v);
    vector<ll> dp(n,v[0]);
    for(int i=1;i<n;i++)
        dp[i]=max(dp[i-1],v[i]-dp[i-1]);
    printf("%lld",dp[n-1]);
    return 0;
}