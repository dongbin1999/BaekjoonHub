#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=2e18;
void f(ll d,ll pl,ll mi){
    //pl -> pl -> mi -> mi
    ll tmp=pl+d+pl+mi+d+mi;
    ans=min(ans,tmp);
    //printf("1 : %lld\n",tmp);
    //pl -> mi -> pl -> mi;
    tmp=pl+pl+mi+mi+pl;
    ll pd=(pl+mi)*2,md=pl+mi;
    ll add=max(0ll,d-pd);
    tmp+=add,md+=add;
    tmp+=pl+mi,md+=pl+mi;
    tmp+=max(0ll,d-md);
    tmp+=mi;
    ans=min(ans,tmp);
    //printf("2 : %lld\n",tmp);
    //pl -> mi -> mi -> pl
    tmp=pl+pl+mi;
    pd=pl+mi,md=0;
    tmp+=d,pd+=d;
    tmp+=mi+pl,pd+=mi+pl;
    tmp+=max(0ll,d-pd);
    tmp+=pl;
    ans=min(ans,tmp);
    //printf("3 : %lld\n",tmp);
}

int main(){
    int n;ll d;scanf("%d%lld",&n,&d);d*=2;
    ll pl=-1,mi=-1;
    while(n--){
        ll x;scanf("%lld",&x);
        x*=2;
        if(x<0)mi=max(mi,-x);
        if(x>0)pl=max(pl,x);
    }
    if(pl==-1&&mi==-1)ans=d;
    else if(pl==-1)ans=mi+d+mi;
    else if(mi==-1)ans=pl+d+pl;
    else{
        f(d,pl,mi),f(d,mi,pl);
    }
    printf("%lld",ans/2);
    return 0;
}