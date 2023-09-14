#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[50000][2];

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]),v[i]*=2;
    sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    n=v.size();
    dp[0][0]=0;
    for(int i=1;i<n;i++){
        ll l=v[i]-v[i-1],r=4e9,mid,mn=r;
        while(l<=r){
            mid=(l+r)/2;
            int x=lower_bound(v.begin(),v.end(),v[i]-mid)-v.begin();
            if(!x||dp[x][0]+2<=mid)mn=min(mn,mid),r=mid-1;
            else l=mid+1;
        }
        dp[i][0]=mn;
    }
    dp[n-1][1]=0;
    for(int i=n-2;i>=0;i--){
        ll l=v[i+1]-v[i],r=4e9,mid,mn=r;
        while(l<=r){
            mid=(l+r)/2;
            int x=upper_bound(v.begin(),v.end(),v[i]+mid)-v.begin()-1;
            if(x==n-1||dp[x][1]+2<=mid)mn=min(mn,mid),r=mid-1;
            else l=mid+1;
        }
        dp[i][1]=mn;
    }
    ll l=0,r=4e9,mid,ans=r;
    while(l<=r){
        mid=(l+r)/2;
        bool ok=0;
        for(int i=0;i<n;i++)
            if(dp[i][0]<=mid&&dp[i][1]<=mid){
                //printf("%lld %d %lld %lld %lld %lld\n",mid,i,dp[i][0],dp[i][1],l,r);
                ok=1;break;
            }
        if(!ok)
            for(int i=0;i<n;i++){
                int x=lower_bound(v.begin(),v.end(),v[i]-mid*2)-v.begin();
                if(dp[x][0]+2<=mid&&dp[i][1]+2<=mid){
                    //printf("%lld %d %d %lld %lld\n",mid,i,x,dp[x][0],dp[i][1]);
                    ok=1;break;
                }
            }
        if(ok)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%lld.%lld",ans/2,ans%2*5);
    return 0;
}