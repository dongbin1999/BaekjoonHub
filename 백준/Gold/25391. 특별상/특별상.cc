#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pll a[200001];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%lld%lld",&a[i].second,&a[i].first);
    sort(a,a+n,greater<pll>());
    ll ans=0;
    for(int i=0;i<k;i++)ans+=a[i].second,a[i].first=a[i].second=0;
    for(int i=0;i<n;i++)swap(a[i].first,a[i].second);
    sort(a,a+n,greater<pll>());
    for(int i=0;i<m;i++)ans+=a[i].first;
    printf("%lld",ans);
}