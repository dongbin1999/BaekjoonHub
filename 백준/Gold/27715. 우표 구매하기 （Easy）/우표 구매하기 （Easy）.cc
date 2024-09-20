#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cmb[2001][2001]={1};

int main(){
    ll n,m,k,p;scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
    ll ans=0;
    for(ll i=1;i<=2000;i++){
        cmb[i][0]=1;
        for(ll j=1;j<=i;j++)cmb[i][j]=(cmb[i-1][j-1]+cmb[i-1][j])%p;
    }
    for(ll i=0,j=k;i+i<=k;i++,j-=2)
        ans=(ans+cmb[max(0ll,m+i-1)][i]*cmb[max(0ll,n+j-1)][j])%p;
    printf("%lld",ans);
}