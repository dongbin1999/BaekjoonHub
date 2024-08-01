#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> D;
bool check(ll n){
    for(auto d:D)if(n%d)return 0;
    return 1;
}

int main(){
    ll n;scanf("%lld",&n);
    ll nn=n;while(nn)D.push_back(max(1ll,nn%10)),nn/=10;
    ll ans=LLONG_MAX;
    ll d=1;
    for(int z=0;z<6;z++){
        for(ll i=0;i<d;i++)
            if(check(n*d+i))ans=min(ans,n*d+i);
        d*=10;
    }
    printf("%lld",ans);
    return 0;
}