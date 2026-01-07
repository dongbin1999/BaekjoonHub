#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    while(1){
        ll x,y;scanf("%lld%lld",&x,&y);
        if(!x&&!y)return 0;
        int gcd=__gcd(x,y);
        printf("%lld\n",x*y/gcd/gcd);
    }
}