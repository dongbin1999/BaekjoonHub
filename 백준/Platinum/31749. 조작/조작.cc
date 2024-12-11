#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
    ll n;scanf("%lld",&n);
    vector<ll> v(n);
    for(auto &x:v)scanf("%lld",&x);
    vector<pll> ans;
    for(ll i=0;i<n-1;i++){
        ll d=-v[i];
        ans.push_back({i,d}),v[i]+=d,v[i+1]+=d;
    }
    if(n%2){
        for(ll i=0;i<n-1;i+=2)
            ans.push_back({i,v.back()}),v[i]+=v.back(),v[i+1]+=v.back();
    }
    else{
        ll x=(abs(v.back())+n/2-1)/(n/2);
        if(v.back()<0)x*=-1;
        for(ll i=n-2;i>=0;i--)
            if(i%2==0){
                ll d=x>0?min(0ll,x-v[i+1]):max(0ll,x-v[i+1]);
                ans.push_back({i,d}),v[i]+=d,v[i+1]+=d;
            }
            else{
                ll d=-v[i+1];
                ans.push_back({i,d}),v[i]+=d,v[i+1]+=d;
            }
    }
    printf("%lld\n%d\n",*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end()),ans.size());
    for(auto [a,b]:ans)printf("%lld %lld\n",a+1,b);
}