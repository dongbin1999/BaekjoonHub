#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n){
    ll ret=0;
    for(ll i=1;i*i<=n;i++){
        ret+=(n/i-i+1)*(i%2?-1:1);
        ll s=i,e=n/i;
        ret+=(e%2?-1:0)-(s%2?-1:0);
    }
    return ret;
}
int main(){
    ll s,t;scanf("%lld%lld",&s,&t);
    printf("%lld",f(t)-f(s-1));
}