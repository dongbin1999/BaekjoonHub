#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    ll n,h;scanf("%lld%lld",&n,&h);
    vector<pll> v(n);
    for(auto &[x,y]:v)scanf("%lld%lld",&x,&y);
    sort(v.begin(),v.end());
    deque<pll> b;
    for(auto [x,y]:v)
        if(b.empty()||b.back().second+1<x)b.push_back({x,y});
        else {
            auto [px,py]=b.back();
            b.pop_back(),b.push_back({px,max(py,y)});
        }
    b.push_front({0,0}),b.push_back({h+1,h+1});
    vector<ll> len,sum(1);
    for(int i=1;i<b.size();i++)len.push_back(b[i].first-b[i-1].second-1);
    sort(len.begin(),len.end());
    for(ll l:len)sum.push_back(sum.back()+l);

    int q;scanf("%d",&q);
    while(q--){
        ll x;scanf("%lld",&x);
        ll i=lower_bound(len.begin(),len.end(),x)-len.begin();
        printf("%lld\n",sum.back()-sum[i]-((ll)len.size()-i)*(x-1));
    }
}