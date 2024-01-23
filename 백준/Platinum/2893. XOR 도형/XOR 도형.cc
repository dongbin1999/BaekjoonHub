#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tup;

tup AND(tup a,tup b){
    auto [ax,ay,ar]=a;auto [bx,by,br]=b;
    ll x=max(ax,bx),y=max(ay,by),r=max(0ll,min(ax+ay+ar,bx+by+br)-x-y);
    return {x,y,r};
}

int main() {
    int n;scanf("%d",&n);
    vector<tup> v(n);
    for(auto&[x,y,r]:v)scanf("%lld%lld%lld",&x,&y,&r);
    ll ans=0;
    for(int i=1;i<1<<n;i++){
        bool b=0;tup t;
        for(int j=0;j<n;j++)if(i>>j&1){
            if(!b)b=1,t=v[j];
            t=AND(t,v[j]);
        }
        auto [x,y,r]=t;
        int cnt=__builtin_popcount(i);
        ans+=(cnt&1?r*r:-r*r)<<(cnt-1);
    }
    printf("%lld.%lld",ans>>1,(ans&1)*5);
}