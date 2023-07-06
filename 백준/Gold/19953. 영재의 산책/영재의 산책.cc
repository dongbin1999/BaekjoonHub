#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll ;
pll go[4]={{-1,0},{0,1},{1,0},{0,-1}};
pll operator+(pll a,pll b){return{a.first+b.first,a.second+b.second};}
pll operator-(pll a,pll b){return{a.first-b.first,a.second-b.second};}
pll operator*(pll a,ll b){return{a.first*b,a.second*b};}

int main(){
    ll v0,m,t;scanf("%lld%lld%lld",&v0,&m,&t);
    pll diff={0,0};
    diff=go[1]*(v0-v0%10),v0%=10ll;
    //printf("diff : %lld %lld\n",diff.first,diff.second);
    ll speed=v0;
    vector<pll> loc={{0,0},go[1]*speed};
    while(loc.size()<3000){
        speed=speed*m%10ll;
        loc.push_back(loc.back()+go[loc.size()%4]*speed);
    }
    pll ans=(loc[2600]-loc[80])*(t/2520)+loc[t%2520]+diff;
    //for(int i=0;i<100;i++)printf("%d : %lld %lld\n",i,loc[i].first,loc[i].second);
    printf("%lld %lld\n",ans.first,ans.second);
}