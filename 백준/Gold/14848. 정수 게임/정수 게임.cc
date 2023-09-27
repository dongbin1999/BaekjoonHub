#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll ans,n,k;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll LCM(ll a,ll b){return a*b/GCD(a,b);}
void f(ll i){
    ll lcm=1;
    for(int j=0;j<k;j++)
        if(i>>j&1){
            lcm=LCM(lcm,v[j]);
            if(n/lcm==0)return;
        }
    ans+=__builtin_popcount(i)&1?n/lcm:-n/lcm;
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<k;i++){
        ll x;scanf("%lld",&x);
        v.push_back(x);
    }
    for(ll i=1;i<1<<k;i++)f(i);
    printf("%lld",n-ans);
    return 0;
}