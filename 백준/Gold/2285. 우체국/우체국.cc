#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pll a[100001];

int main() {
    ll b=0,n;scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld %lld",&a[i].first,&a[i].second),b+=a[i].second;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b-=a[i].second*2;
        if(b<=0)return !printf("%lld",a[i].first);
    }
}