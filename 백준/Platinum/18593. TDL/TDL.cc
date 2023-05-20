#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1000;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}

ll f(ll n,ll m){
    ll ret=0;
    for(ll i=n+1;i<=n+sz;i++){
        if(GCD(i,n)==1ll)ret++;
        if(ret==m) return i;
    }
    return 3e18;
}

void solve(){
    ll k,m;scanf("%lld %lld",&k,&m);
    ll ans=3e18;
    for(ll XOR=0;XOR<=sz;XOR++){
        ll n=XOR^k;
        if(f(n,m)-n==XOR)ans=min(ans,n);
    }
    printf("%lld\n",ans>2e18?-1ll:ans);
}

int main(){
    int tc;scanf("%d",&tc);
    for(int TC=1;TC<=tc;TC++){
        solve();
    }
    return 0;
}