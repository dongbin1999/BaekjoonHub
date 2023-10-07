#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n);
    ll sum=0,cnt=0;
    for(int i=0;i<n;i++)scanf("%lld%lld",&v[i].first,&v[i].second),sum+=v[i].second;
    sort(v.begin(),v.end(),greater<pll>());
    for(auto [a,b]:v){
        cnt+=b;
        if(cnt+cnt>=sum)return !printf("%lld",a);
    }
    return 0;
}