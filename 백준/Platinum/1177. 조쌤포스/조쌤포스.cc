#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double,double> pdd;

int main(){
    int n;ll r,x,y,dx,dy;scanf("%d%lld%lld%lld%lld%lld",&n,&r,&x,&y,&dx,&dy);
    vector<pdd> v;
    int ok=0;
    while(n--){
        ll ax,ay,adx,ady;scanf("%lld%lld%lld%lld",&ax,&ay,&adx,&ady);
        ll _1=x-ax,_2=y-ay,_3=dx-adx,_4=dy-ady;
        ll a=_3*_3+_4*_4,b=_1*_3*2+_2*_4*2,c=_1*_1+_2*_2-r*r;
        //printf("%lld %lld %lld\n",a,b,c);
        ll d=b*b-a*c*4;
        if(d<0)continue;
        if(!a&&!b){
            ok+=c<=0;
            continue;
        }
        if(!a)assert(0),v.push_back({0,-c/b});
        else v.push_back({(-sqrt(d)-b)/a/2,(sqrt(d)-b)/a/2});
        if(v.back().second<0)v.pop_back();
        v.back().first=max(0.0,v.back().first);
    }
    vector<pdd> vv;
    for(auto [a,b]:v)
        vv.push_back({a,-1}),vv.push_back({b,1});
    sort(vv.begin(),vv.end());
    int ans=0,cnt=0;
    for(auto [a,b]:vv){
        cnt-=b;
        ans=max(ans,cnt);
    }
    printf("%d",ans+ok);
}