#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    ll a[n+1],XOR=0,sum=0;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),XOR^=a[i],sum+=a[i];
    if(XOR==0){
        printf("%lld\n",sum);
        vector<ll> ans={(ll)2e18,0,0};
        for(int i=1;i<=n;i++){
            ll mi=1,after=XOR^a[i]^(a[i]-1);
            ans=min(ans,{after,i,mi});
        }
        printf("%lld %lld",ans[1],ans[2]);

    }
    else{
        vector<ll> ans={(ll)2e18,0,0};
        for(int i=1;i<=n;i++){
            ll mi=a[i]-(XOR^a[i]);
            if(mi<=0)continue;
            ans=min(ans,{sum+1-mi,i,mi});
        }
        printf("%lld\n%lld %lld",ans[0],ans[1],ans[2]);
    }
    return 0;
}