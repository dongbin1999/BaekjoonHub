#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;scanf("%d",&n);
    if(!n)return !printf("0");
    vector<pll> v(n+1);
    ll YE,MO[13]={0},DA,HO,MI,SE=1;
    ll mul[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    MI=SE*60;HO=MI*60;DA=HO*24;
    for(int i=1;i<=12;i++)MO[i]=MO[i-1]+DA*mul[i];
    YE=MO[12];
    for(int i=1;i<=n;i++){
        ll y,m,d,h,s,l;
        scanf("%lld/%lld/%lld",&y,&m,&d);
        ll t=YE*(y-2019)+MO[m-1]+DA*(d-1);
        if(y>2020||(y==2020&&m>=3))t+=DA;
        scanf("%lld:%lld:%lld",&h,&m,&s);
        t+=HO*h+MI*m+SE*s;
        scanf("%lld",&l);
        v[i]={t,l};
    }
    double d=0,sum=0;
    for(int i=1;i<=n;i++){
        double p=pow(0.5,(v[n].first-v[i].first)/(double)YE);
        p=max(p,pow(0.9,n-i));
        d+=p,sum+=p*(double)v[i].second;
    }
    printf("%lld",(ll)round(sum/d));
}