#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,d;scanf("%lld%lld",&n,&d);
    ll g=gcd(n,d);n/=g,d/=g;
    if(__builtin_popcount(d)>1)return !printf("-1");
    string s;
    while(d>1)d>>=1,s+='D';
    while(n){
        if(n&1)s+=n<0?'L':'R';
        n/=2,s+='U';
    }

    printf("%d\n",s.size());
    for(auto c:s)printf("%c",c);
}