#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
    ll ans=2e9;
    for(ll i=1;i*i<=c;i++){
        if(c%i)continue;
        ll x=i,y=c/i,cnt=0,aa=a,bb=b;
        if(a<x||b<y)cnt=2e9;
        else{
            while(x<aa)cnt++,aa=(aa+1)/2;
            while(y<bb)cnt++,bb=(bb+1)/2;
        }
        ans=min(ans,cnt);
        x=c/i,y=i,cnt=0,aa=a,bb=b;
        if(a<x||b<y)cnt=2e9;
        else{
            while(x<aa)cnt++,aa=(aa+1)/2;
            while(y<bb)cnt++,bb=(bb+1)/2;
        }
        ans=min(ans,cnt);
    }
    printf("%lld",ans>1e9?-1:ans);
}