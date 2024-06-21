#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
pbds se;
ll fac[300001]={1};

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<n;i++)scanf("%d",&v[i]),se.insert(v[i]);
    ll ans=1,y=n-1;
    for(auto i:v){
        ll x=se.order_of_key(i);
        ans=(ans+fac[y--]*x)%mod;
        se.erase(se.find(i));
    }
    printf("%lld",ans);
}