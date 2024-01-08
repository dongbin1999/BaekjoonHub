#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    unordered_set<ll> se={v[0],v[0]+1};
    for(int i=1;i<n;i++){
        unordered_set<ll> nx;
        for(int add=0;add<=1;add++)
            for(auto j:se)nx.insert(__gcd(j,v[i]+add));
        se=nx;
    }
    ll ans=1;
    for(auto i:se)ans=max(ans,i);
    printf("%lld",ans);
    return 0;
}