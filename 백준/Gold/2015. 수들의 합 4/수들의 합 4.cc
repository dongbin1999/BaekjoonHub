#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> ma;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> v(n);ll sum=0;
    for(auto &x:v)scanf("%lld",&x),sum+=x,ma[sum]++;
    ll ans=0;sum=0;
    for(auto i:v)
        ans+=ma[k+sum],sum+=i,ma[sum]--;
    printf("%lld",ans);
    return 0;
}