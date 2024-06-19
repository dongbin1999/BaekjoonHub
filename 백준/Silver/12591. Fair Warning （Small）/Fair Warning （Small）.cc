#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;scanf("%d",&n);
    vector<ll> v(n);for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    ll GCD=abs(v[0]-v[1]);
    if(n==3)GCD=gcd(GCD,abs(v[1]-v[2]));
    ll ans=2e18;
    for(auto i:v)
        ans=min(ans,(i+GCD-1)/GCD*GCD-i);
    printf("%lld\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}