#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll s,c;scanf("%lld%lld",&s,&c);
    vector<ll> v(s);
    for(auto &x:v)scanf("%lld",&x);
    ll l=0,r=1e10,mid,mx=l;
    while(l<=r){
        mid=(l+r)/2;
        ll sum=0;
        for(auto i:v)sum+=i/mid;
        if(sum>=c)mx=max(mx,mid),l=mid+1;
        else r=mid-1;
    }
    ll sum=0,ans=0;
    for(auto i:v)ans+=i%mx,sum+=i/mx;
    printf("%lld",ans+(sum-c)*mx);
}