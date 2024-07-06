#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500001];

int main(){
    int n;ll k;scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    ll x=0,ans=-2e18;
    for(int i=1;i<n;i++){
        ll cur=a[i]-a[i+1]-k;
        x=max(x,0ll);
        x+=cur;
        ans=max(ans,x);
    }
    x=0;
    for(int i=n;i>1;i--){
        ll cur=a[i]-a[i-1]-k;
        x=max(x,0ll);
        x+=cur;
        ans=max(ans,x);
    }
    printf("%lld",ans);
    return 0;
}