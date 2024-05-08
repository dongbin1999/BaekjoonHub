#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,l;scanf("%lld%lld",&n,&l);
    for(ll len=l;len<=100;len++){
        ll mid=n/len,le=mid-len/2,ri=mid+len/2;
        if(len%2==0)le++;
        if(le<0)continue;
        if((le+ri)*len/2==n){
            for(ll i=le;i<=ri;i++)printf("%lld ",i);
            return 0;
        }
    }
    printf("-1");
}