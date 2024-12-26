#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;scanf("%d",&n);
    vector<ll> v(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        sum+=v[i];
    }
    ll x=0;
    bool ok=1;
    if(v.back()>2)ok=0;
    if(sum!=(v[1]-1)*2)ok=0;
    if(n>=2&&v[2]*2>v[1])ok=0;
    for(int i=2;i<=n;i++)if(v[i]>v[i-1])ok=0;
    for(int i=n;i>=2;i--){
        ll y=v[i]==1?3:v[i]*2;
        if(x+y<v[i-1])ok=0;
        x=x+y-v[i-1];
    }
    if(x)ok=0;
    printf(ok?"YES\n":"NO\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}