#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,w;scanf("%lld%lld",&n,&w);
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
        if(i&&v[i-1]<v[i]){
            ll c=w/v[i-1];
            w+=(v[i]-v[i-1])*c;
        }
    }
    printf("%lld",w);
    return 0;
}