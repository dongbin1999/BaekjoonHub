#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    ll g=v[1]-v[0];
    for(int i=2;i<n;i++)g=gcd(g,v[i]-v[i-1]);
    ll ans=0;
    for(int i=1;i<n;i++)ans+=(v[i]-v[i-1])/g-1;
    printf("%lld",ans);
}