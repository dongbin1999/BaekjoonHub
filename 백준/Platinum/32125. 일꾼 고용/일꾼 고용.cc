#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;ll k;scanf("%d%lld",&n,&k);
    map<ll,ordered_set> ma;
    ma[0].insert({0,-1});
    vector<ll> c(n),w(n);
    for(int i=0;i<n;i++)scanf("%lld",&c[i]);
    ll cur=0,sum=0,ans=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&w[i]);
        if(c[i]==1)cur--,sum-=w[i];
        else cur++,sum+=w[i];
        auto x=ma[cur].lower_bound({sum-k,-1e9}),y=ma[cur].upper_bound({sum+k,1e9});
        ll l=x==ma[cur].end()?ma[cur].size():ma[cur].order_of_key(*x),
        r=y==ma[cur].end()?ma[cur].size():ma[cur].order_of_key(*y);
        ma[cur].insert({sum,i}),ans+=r-l;
    }
    printf("%lld\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}