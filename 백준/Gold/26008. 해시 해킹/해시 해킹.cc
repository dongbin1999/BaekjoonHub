#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
    int n,m;ll a,h;scanf("%d%d%lld%lld",&n,&m,&a,&h);
    ll d=1;
    for(int i=1;i<n;i++){d=(d*m)%mod;}
    printf("%lld",d);
    return 0;
}