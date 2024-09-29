#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x,y,z;scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
    ll l=1,r=2e18,mid,t=r;
    while(l<=r){
        mid=(l+r)/2;
        ll pop=mid/x+mid/y+mid/z;
        if(pop>=n)t=min(t,mid),r=mid-1;
        else l=mid+1;
    }
    ll pre=(t-1)/x+(t-1)/y+(t-1)/z;
    if(t%x==0)pre++;if(pre==n)return !printf("A win");
    if(t%y==0)pre++;if(pre==n)return !printf("B win");
    if(t%z==0)pre++;if(pre==n)return !printf("C win");
}