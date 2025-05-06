#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;scanf("%lld%lld",&n,&k);
    ll x;
    vector<ll> v;
    while(k){
       ll kk=k,d=0;
       while(kk)x=kk%10,kk/=10,d=d*10+1;
       if(d*x>k){
           if(x==1)d/=10,x=9;
           else x--;
       }
       v.push_back(d*x),k-=d*x;
    }
    printf("%d\n",v.size());
    for(auto i:v)printf("%lld ",i);
    printf("\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}