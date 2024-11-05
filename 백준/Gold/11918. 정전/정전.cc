#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    ll l[2]={INT_MIN,INT_MIN},r[2]={INT_MIN,INT_MIN};
    ll ans=0;
    for(int i=0;i<n;i++){
        ll L=v[i]-k,R=v[i]+k,b=i%2;
        ans-=max(0ll,r[b]-L);
        l[b]=max(l[b],L),r[b]=R;
        ans+=max(0ll,r[!b]-l[b]);
    }
    printf("%lld",ans);
}