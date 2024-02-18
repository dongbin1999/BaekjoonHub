#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;int q;scanf("%lld%d",&k,&q);
    ll kk=k;
    map<ll,ll> ma;
    for(ll i=2;i*i<=k;i++)
        while(kk%i==0)ma[i]++,kk/=i;
    if(kk>1)ma[kk]++;

    while(q--){
        ll a;scanf("%lld",&a);
        map<ll,ll> ma2=ma;
        for(auto &[x,y]:ma2)
            while(a%x==0)y--,a/=x;
        auto p=prev(ma2.end());
        if(p->second>0&&p->first>sqrt(k)*2){
            printf("%lld ",p->first);
            continue;
        }
        ll l=1,r=sqrt(k)*2+5,mid,ans=r;
        while(l<=r){
            mid=(l+r)/2;
            bool ok=1;
            map<ll,ll> ma3=ma2;
            for(auto &[x,y]:ma3){
                ll z=mid;
                while(z&&y>0)y-=z/x,z/=x;
                ok&=y<=0;
            }
            if(ok)ans=min(ans,mid),r=mid-1;
            else l=mid+1;
        }
        printf("%lld ",ans);
    }
    return 0;
}