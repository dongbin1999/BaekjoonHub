#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef array<ll,3> tup;
tup EEA(ll a,ll b,ll x1=1,ll x2=0,ll y1=0,ll y2=1){
    if(b==0)return {a,x1,y1};
    ll q=a/b,r=a%b,x=x1-q*x2,y=y1-q*y2;
    return EEA(b,r,x2,x,y2,y);
}
int main(){
    long long a,b,s;scanf("%lld%lld%lld",&a,&b,&s);
    if(a==s||b==s)return !printf("YES");
    if(!a&&!b)return !printf(s?"NO":"YES");
    if(!a)return !printf(s%b?"NO":"YES");
    if(!b)return !printf(s%a?"NO":"YES");

    auto [gcd,xx,yy]=EEA(a,b);
    if(s%gcd)return !printf("NO");
    a/=gcd,b/=gcd,s/=gcd;
    ll x=xx*s,y=yy*s;
    if(x<1){
        ll need=abs(x)/b+1;
        x+=b*need,y-=a*need;
    }
    if(y<1){
        ll need=abs(y)/a+1;
        x-=b*need,y+=a*need;
    }
    if(x>=1&&y>=1&&EEA(x,y)[0]==1)return !printf("YES");
    for(int i=0;i<100;i++){
        x-=b,y+=a;
        if(x>=1&&y>=1&&EEA(x,y)[0]==1)return !printf("YES");
    }
    for(int i=0;i<200;i++){
        x+=b,y-=a;
        if(x>=1&&y>=1&&EEA(x,y)[0]==1)return !printf("YES");
    }
    printf("NO");
}