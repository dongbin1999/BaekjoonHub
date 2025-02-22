#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        ll x,y;scanf("%lld/%lld",&x,&y);
        ll gcd=__gcd(x,y);
        x/=gcd,y/=gcd;
        ll ans=0;
        while(x<y)ans++,x*=2;
        while(y%2==0)y/=2;
        if(y!=1)printf("impossible\n");
        else printf("%lld\n",ans);
    }
}