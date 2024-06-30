#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pll mn[500002],r[500002];
ll a[500002];

int main(){
    int n;ll k;scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    memset(mn,0x3f,sizeof(mn));memset(r,0x3f,sizeof(r));
    for(int i=1;i<=n;i++)
        mn[i]=min(mn[i-1],{a[i]-k*i,i});
    for(int i=n;i>=1;i--)
        r[i]=min(r[i+1],{a[i]+k*i,i});
    ll ans=-2e18;
    for(int i=1;i<=n;i++){
        ll x=mn[i-1].second,y=r[i+1].second;
        if(x<1e9)ans=max(ans,a[i]-abs(x-i)*k-a[x]);
        if(y<1e9)ans=max(ans,a[i]-abs(y-i)*k-a[y]);
    }
    printf("%lld",ans);
}