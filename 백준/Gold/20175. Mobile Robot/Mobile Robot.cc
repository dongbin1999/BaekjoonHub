#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,d,sum;scanf("%lld%lld",&n,&d);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    sum=0;ll x[2]={0};
    for(int i=1;i<n;i++){
        sum+=v[i]-v[i-1]-d;
        x[0]=min(x[0],sum);
        x[1]=max(x[1],sum);
    }
    sum=0;ll y[2]={0};
    for(int i=1;i<n;i++){
        sum+=v[i]-v[i-1]+d;
        y[0]=min(y[0],sum);
        y[1]=max(y[1],sum);
    }
    ll k=min(x[1]-x[0],y[1]-y[0]);
    printf("%lld.%lld",k/2,k%2*5);
    return 0;
}