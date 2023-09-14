#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,w;scanf("%lld%lld",&w,&n);
    vector<ll> v(n+1),sum(n+1);
    ll l=1e9,r=w,mid,cnt;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        l=min(l,v[i]);
        sum[i]=v[i]+sum[i-1];
    }
    ll ans=l;
    while(l<=r){
        mid=(l+r)/2;
        vector<int> dp(n+2);
        dp[0]++,dp[1]--,cnt=0;
        for(int i=0;i<=n;i++){
            cnt+=dp[i];
            if(!cnt||i==n)continue;
            int x=lower_bound(sum.begin()+i,sum.end(),sum[i]+mid)-sum.begin(),
            y=upper_bound(sum.begin()+i,sum.end(),sum[i]+w)-sum.begin()-1;
            if(x>y)continue;
            dp[x]++,dp[y+1]--;
        }
        if(cnt)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    ans=w-ans;
    printf("%lld",ans*ans);
    return 0;
}