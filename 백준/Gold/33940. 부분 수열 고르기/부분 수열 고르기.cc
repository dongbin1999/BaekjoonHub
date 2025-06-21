#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,a,d,m;scanf("%lld%lld%lld%lld",&n,&a,&d,&m);
    for(ll x=min(3000000ll,n);x>=1;x--){
        if((m-a*x)%d)continue;
        ll k=(m-a*x)/d;
        if(x*(x-1)/2>k||(n-1+n-x)*x/2<k)continue;
        vector<ll> ans;
        ll r=x-1,p=n-1;
        while(ans.size()<x){
            ll c=min(k-r*(r-1)/2,p);
            ans.push_back(c*d+a),k-=c;
            r--,p--;
        }
        sort(ans.begin(),ans.end());
        printf("%lld\n",x);
        for(auto i:ans)printf("%lld ",i);
        return 0;
    }
    return !printf("-1");
}
