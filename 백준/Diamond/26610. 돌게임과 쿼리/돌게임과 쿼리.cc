#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pair<ll,ll> range(ll x,ll n,ll t){
    ll mx=x*n+(n+1)*n/2,d=n/t,r=n%t;
    ll mn=x*n+t*(d+1)*d/2+(d+1)*r;
    return {mn,mx};
}

pair<ll,ll> range2(ll x,ll n,ll t,ll turns){//x가 n개.
    ll ts=(n-turns)/(t-1),remain=(n-turns)%(t-1);//온전히 t개인 숫자가 ts개, 하나는 remain+1개, 나머지는 1개.
    if(turns*t==n)remain=-1;
    ll l=1,r=ts,len=max(0ll,n-(ts*t+remain+1));
    ll mn=x*n+(r+1)*(remain+1)+(l+r)*(r-l+1)/2*t;
    l=r+2,r=l+len-1;
    if(len)mn+=len*(l+r)/2;

    r=turns,l=r-ts+1;
    ll mx=x*n+(l-1)*(remain+1)+(l+r)*(r-l+1)/2*t;
    r=l-2,l=r-len+1;
    if(len)mx+=len*(l+r)/2;
    //printf("%lld %lld %lld %lld-> %lld %lld %lld [%lld %lld]\n",x,n,t,turns,ts,remain,len,mn,mx);
    return {mn,mx};
}

void solve(){
    ll x,t,n;scanf("%lld%lld%lld",&x,&t,&n);
    ll l=1,r=5e8,mid;
    pll ans={-1,-1};
    while(l<=r){
        mid=(l+r)/2;
        auto [mn,mx]=range(x,mid,t);
        if(mn<=n){
            ans=max(ans,{min(mx,n),mid});
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }

    l=1,r=5e8;
    pll ans2={-1,-1};
    while(l<=r){
        mid=(l+r)/2;
        auto [mn,mx]=range(x,mid,t);
        if(mn<=n){
            ans2=max(ans,{min(mx,n),-mid});
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }

    l=(ans.second+t-1)/t,r=ans.second;
    ll turn=2e18;
    while(l<=r){
        mid=(l+r)/2;
        auto [mn,mx]=range2(x,ans.second,t,mid);
        if(mn<=ans.first&&ans.first<=mx){
            turn=min(turn,mid);
            r=mid-1;
        }
        else if(mx<ans.first){//최대한 크게 만들어도 돌을 다 못가져가면, 턴수를 늘려야됨.
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    l=1,r=-ans2.second;
    while(l<=r){
        mid=(l+r)/2;
        auto [mn,mx]=range2(x,-ans2.second,t,mid);
        if(mn<=ans.first&&ans.first<=mx){
            turn=min(turn,mid);
            r=mid-1;
        }
        else if(mx<ans.first){//최대한 크게 만들어도 돌을 다 못가져가면, 턴수를 늘려야됨.
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    printf("%lld\n",turn);
}

int main(){
    int q;scanf("%d",&q);
    while(q--)solve();
    return 0;
}