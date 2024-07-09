#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[50001]={1,1};

int main(){
    ll n;scanf("%lld",&n);
    for(ll i=2;i<=n;i++)
        for(ll j=i;j<=n;j+=i)
            if(!p[j])p[j]=i;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        vector<ll> v;
        ll x=i;
        while(p[x]>1){
            if(v.empty()||v.back()!=p[x])v.push_back(p[x]);
            x/=p[x];
        }
        ll sub=0;
        for(int b=1;b<1<<v.size();b++){
            ll d=1;
            for(int j=0;j<v.size();j++)
                if(b>>j&1)d*=v[j];
            if(__builtin_popcount(b)&1)sub+=n/d;
            else sub-=n/d;
        }
        ans+=n-sub;
    }
    printf("%lld",ans/2);
    return 0;
}