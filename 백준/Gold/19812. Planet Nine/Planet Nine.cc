#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    printf("Stable\n");
    vector<pll> ans;
    while(n>=10){
        ll x=1,nn=n,last=-1;
        while(nn)last=nn%10,nn/=10,x*=10;
        if(last==1){
            ans.push_back({0,1}),n-=x/10;
            continue;
        }
        x+=x/10;
        ll l=1,r=n,mid,mn=2e18;
        while(l<=r){
            mid=(l+r)/2;
            if(mid*9+n>=x)mn=min(mn,mid),r=mid-1;
            else l=mid+1;
        }
        ans.push_back({1,mn}),n+=mn*9;
        ans.push_back({0,2}),n-=x;
    }

    while(n!=k%9){
        n+=9,ans.push_back({1,1});
        if(n>=10)n-=10,ans.push_back({0,1});
    }

    if(k/9)ans.push_back({1,k/9}),n+=k/9*9;

    printf("%d\n",ans.size());
    for(auto [x,y]:ans){
        printf(x?"+ ":"- ");
        printf("%lld\n",y);
    }
}