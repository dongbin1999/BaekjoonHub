#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t,n;scanf("%lld %lld",&t,&n);
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
    ll m;scanf("%lld",&m);
    vector<ll> b(m+1);
    for(int i=1;i<=m;i++)scanf("%lld",&b[i]),b[i]+=b[i-1];
    vector<ll> va;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)va.push_back(a[j]-a[i-1]);
    sort(va.begin(),va.end());
    ll ans=0;
    for(int i=1;i<=m;i++)for(int j=i;j<=m;j++){
        ll x=b[j]-b[i-1];
        auto l=lower_bound(va.begin(),va.end(),t-x),r=upper_bound(va.begin(),va.end(),t-x);
        ans+=r-l;
    }
    printf("%lld",ans);
    return 0;
}