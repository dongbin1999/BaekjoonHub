#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rmx,sum,n;
vector<ll> lsum;
__int128 f(ll x,ll fix){
    //rmx + sum-n^2*1 + ... + sum-n^2*x + v[l]-n*(x+1) + ... + v[fix]-n*(x+1)
    __int128 _rmx=rmx,_sum=sum,_n=n,_x=x,_lsum=lsum[fix],_fix=fix;
    //printf("rmx : %lld sum : %lld n : %lld x : %lld lsum : %lld fix : %lld val : %lld\n",rmx,sum,n,x,lsum[fix],fix,_rmx+(_sum*2+_n*_n*(_x+1))*_x/2+_lsum-_n*(_x+1)*_fix);
    return _rmx+(_sum*2-_n*_n*(_x+1))*_x/2+_lsum-_n*(_x+1)*_fix;
}

int main(){
    scanf("%lld",&n);
    vector<ll> v(n+2),mx(n+2),rsum(n+2);
    lsum.assign(n+2,0);
    for(ll i=1;i<=n;i++)scanf("%lld",&v[i]),v[i]-=i;
    for(int i=n;i>=1;i--)sum+=v[i],rsum[i]=sum,mx[i]=max(0ll,mx[i+1]+v[i]);
    sum=0; for(int i=1;i<=n;i++)sum+=v[i],lsum[i]=sum;
    ll ans=*max_element(mx.begin(),mx.end());
    rmx=*max_element(rsum.begin(),rsum.end());
    for(ll fix=0;fix<=n;fix++){
        ll l=0,r=3e9,lmid,rmid;
        while(l+3<r){
            lmid=(l+l+r)/3,rmid=(l+r+r)/3;
            if(f(lmid,fix)>f(rmid,fix))r=rmid;
            else l=lmid;
        }
        __int128 tmp=0;
        for(ll i=l;i<=r;i++)tmp=max(tmp,f(i,fix));
        ans=max(ans,(ll)tmp);
    }
    printf("%lld",ans);
    return 0;
}