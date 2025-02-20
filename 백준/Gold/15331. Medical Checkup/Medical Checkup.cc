#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,t;scanf("%lld%lld",&n,&t);
    ll sum=0,pre=0;
    while(n--){
        ll x;scanf("%lld",&x);
        if(x>pre)sum+=pre,pre=x;
        else sum+=x;
        printf("%lld\n",max(1ll,(t-sum)/pre+1));
    }
}