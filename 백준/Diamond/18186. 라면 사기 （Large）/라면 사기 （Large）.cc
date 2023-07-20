#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,b,c;scanf("%lld%lld%lld",&n,&b,&c);
    ll ans=0;
    vector<ll> a(n+2);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]),ans+=a[i];
    if(b<=c)return !printf("%lld",ans*b);
    ans=0;
    for(int i=0;i<n;i++){
        ll t=max(0ll,min({a[i],a[i+1],a[i+2],a[i]+a[i+2]-a[i+1]}));
        a[i]-=t,a[i+1]-=t,a[i+2]-=t,ans+=t*(b+c+c);
        t=min(a[i],a[i+1]);
        a[i]-=t,a[i+1]-=t,ans+=t*(b+c);
        ans+=a[i]*b,a[i]=0;
    }
    printf("%lld",ans);
}