#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main() {
    int n,k;scanf("%d%d",&n,&k);
    ll base=0,zero=0;
    vector<ll> v,ans;
    while(n--){
        ll x;scanf("%lld",&x);
        if(x<0)base+=x,v.push_back(-x);
        else v.push_back(x);
    }
    sort(v.begin(),v.end());
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    if(base)ans.push_back(base);
    pq.push({v[0],0});
    while(ans.size()<k){
        auto[sum,l]=pq.top();pq.pop();
        ans.push_back(sum+base);
        if(base&&!(sum+base)&&!zero)ans.pop_back(),zero=1;
        if(l+1==v.size())continue;
        pq.push({sum-v[l]+v[l+1],l+1});
        pq.push({sum+v[l+1],l+1});
    }
    for(auto i:ans)printf("%lld\n",i);
}