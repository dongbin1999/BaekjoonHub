#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    map<ll,ll> ma;
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        ma[x%k]++;
    }
    ll two[100001]={1};
    for(int i=1;i<=100000;i++)two[i]=(two[i-1]*2ll)%mod;
    ll ans=ma[0]+1,l=1,r=k-1;
    while(l<=r){
        ll d;if(l<r)d=(two[ma[l]]+two[ma[r]]-1)%mod;
        else d=ma[l]+1;
        ans=(ans*d)%mod;
        l++,r--;
    }
    ans=(ans+mod-n-1)%mod;
    printf("%lld",ans);
    return 0;
}