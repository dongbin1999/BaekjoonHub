#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main(){
    int l,r;scanf("%d%d",&l,&r);
    ll a=1,b=1,ans=0;
    for(int i=1;i<=r;i++){
        if(i%2)a=(a*5)%mod,b=(b*2)%mod;
        if(i>=l)ans=(ans+a+b)%mod;
    }
    printf("%lld\n",ans);
}