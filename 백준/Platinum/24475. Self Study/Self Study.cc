#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;scanf("%lld%lld",&n,&m);
    vector<ll> a(n),b(n);
    for(auto &x:a)scanf("%lld",&x);
    for(auto &x:b)scanf("%lld",&x);
    ll l=0,r=2e18,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        ll mm=0,over=0;
        for(int i=0;i<n;i++){
            ll cnt=0,tmp=mid;
            if(a[i]>b[i])cnt+=min(m,(tmp-1+a[i])/a[i]),tmp-=cnt*a[i];
            cnt+=max(0ll,(tmp-1+b[i])/b[i]);
            mm+=cnt;
            over|=m*n<mm;
        }
        if(!over)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
}