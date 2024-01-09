#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll a[1<<18],mx[1<<19];
pll b[1<<18];

void update(ll x,ll y){
    a[x]=y;
    while(x){
        (x%2?b[x/2].second:b[x/2].first)=max(b[x].first,b[x].second)+a[x];
        mx[x]=max({mx[x*2],mx[x*2+1],b[x].first+b[x].second+a[x]});
        x/=2;
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),update(i,a[i]);
    printf("%lld\n",mx[1]);
    int q;scanf("%d",&q);
    while(q--){
        ll x,y;scanf("%lld%lld",&x,&y);
        update(x,y);
        printf("%lld\n",mx[1]);
    }
}