#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n);
    for(auto&[x,y]:v)scanf("%lld%lld",&x,&y);
    sort(v.begin(),v.end());
    ll l=0,r=2e9,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        bool ok=1;
        ll p=v[0].first;
        for(int i=1;i<n;i++){
            auto [x,y]=v[i];
            p=max(x,p+mid);
            if(p>x+y){ok=0;break;}
        }
        if(ok)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}