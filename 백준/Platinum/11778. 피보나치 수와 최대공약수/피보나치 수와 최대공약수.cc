#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int sz=2;
ll a[sz][sz],b[sz][sz]={1,1,1};

void mul(bool o){
    ll tmp[sz][sz];
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
        ll x=0;
        for(int k=0;k<sz;k++)x=(x+a[i][k]*(o?b:a)[k][j])%mod;
        tmp[i][j]=x;
    }
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)a[i][j]=tmp[i][j];
}
void power(long long x){
    if(x==1){
        for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)a[i][j]=b[i][j];
        return;
    }
    power(x/2),mul(0);
    if(x&1)mul(1);
}

int main(){
    ll n,m;scanf("%lld%lld",&n,&m);
    power(gcd(n,m)+1);
    printf("%lld",a[1][1]);
    return 0;
}