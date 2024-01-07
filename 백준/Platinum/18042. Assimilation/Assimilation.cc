#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,ans=0;ll k,sum=0;scanf("%d%lld",&n,&k);
    multiset<ll> se;
    while(n--){
        ll x;scanf("%lld",&x);
        se.insert(x),sum+=x;
    }
    while(!se.empty()){
        if(sum<=k){se.clear();break;}
        auto it=se.upper_bound(k);
        if(it!=se.begin())it--;
        else break;
        k+=*it,sum-=*it,ans++;
        se.erase(it);
    }
    printf("%d\n",se.empty()?ans:-1);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}