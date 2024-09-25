#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
 
struct compare{
    bool operator()(plll a,plll b){
        auto [ax,ay]=a.first;auto [bx,by]=b.first;
        return ax*by==bx*ay?a.second<b.second:ax*by<bx*ay;
    }
};
 
ll x,y,k;
pll efficiency(ll z){return {(z+x-1)/x,(z+x+y-1)/(x+y)};}
 
int main(){
    scanf("%lld%lld%lld",&x,&y,&k);
    vector<plll> v;
    v.push_back({efficiency(k),k});
    ll base=k/(x+y)*(x+y)+1;
    if(base<k)base+=x+y;
    for(ll add=0;add<=x+y;add++)
        v.push_back({efficiency(base+(x+y)*add),base+(x+y)*add});
    sort(v.begin(),v.end(),compare());
    printf("%lld",v[0].second);
    return 0;
}