#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int q;scanf("%d",&q);
    map<ll,ll> ma;
    while(q--){
        ll c,a,b;scanf("%lld%lld%lld",&c,&a,&b);
        if(c==1)ma[b]=a;
        else{
            ll ans=a+b;
            while(a!=b){
                if(a>b)swap(a,b);
                b=ma[b]?ma[b]:b>>1;
                ans+=b;
            }
            printf("%lld\n",ans-a);
        }
    }
    return 0;
}