#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll query(ll x){
    printf("query %lld\n",x);
    fflush(stdout);
    ll ret;scanf("%lld",&ret);
    return ret;
}

int main(){
    ll ans=0,d=1,init=query(0);
    while(d<1e18){
        ll l=0,r=9,mid,num=0;
        while(l<=r){
            mid=(l+r)/2;
            if(query(mid*d)<init+mid)r=mid-1;
            else num=max(num,mid),l=mid+1;
        }
        ans+=d*(9ll-num);
        d*=10;
    }
    printf("answer %lld",ans);
    return 0;
}