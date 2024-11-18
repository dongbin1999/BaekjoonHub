#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;scanf("%d",&n);
    vector<ll> v;
    ll a=0,b=0;
    while(n--){
        ll x;scanf("%lld",&x);
        if(x%2)a++;
        b+=x/2;
    }
    if(!a)printf("%lld\n",b*2);
    else printf("%lld\n",b/a*2+1);
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}