#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll h;scanf("%lld",&h);
    ll cnt=0;
    if(h<=4)return !printf("-1");
    ll x=0;
    while(h>1){
        if(h&1)return !printf("-1");
        else x++,h>>=1;
    }
    ll y=0;
    while(x>1){
        if(x&1)return !printf("-1");
        else y++,x>>=1;
    }
    x=y+1;
    printf("%lld %lld\n",x,x);
    for(int i=1;i<x;i++)printf("1 ");
    printf("\n");
    for(int i=2;i<x;i++)printf("1 ");
    printf("2");
}