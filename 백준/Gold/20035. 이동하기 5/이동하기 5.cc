#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;scanf("%lld%lld",&n,&m);
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<m;i++)scanf("%lld",&b[i]);
    int amx=*max_element(a.begin(),a.end()),bmx=*max_element(b.begin(),b.end());
    ll ans=(accumulate(a.begin(),a.end(),0ll)+amx*(m-1))*1000000000ll;
    ans+=bmx*(n-1)+accumulate(b.begin(),b.end(),0ll);
    int l=0;while(a[l]<amx)ans+=b[0]-bmx,l++;
    int r=n-1;while(a[r]<amx)ans+=b[m-1]-bmx,r--;
    printf("%lld",ans);
}