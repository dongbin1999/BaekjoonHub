#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tup;

vector<tup> graph[10001];

int main(){
    ll fac[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        ll a,b,k,l;scanf("%lld%lld%lld%lld",&a,&b,&l,&k);
        graph[a].push_back({l,k,b});
        graph[b].push_back({l,k,a});
    }
    vector<ll> tmp(n+1,9e18);
    vector<vector<ll>> d(11,tmp);
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,1,1});
    while(!pq.empty()){
        tup cur=pq.top();pq.pop();
        ll node=get<2>(cur),s=get<1>(cur),dist=get<0>(cur);
        for(ll add=-1;add<=1;add++){
            ll speed=s+add;
            if(speed>=1&&speed<=10&&d[speed][node]>8e18){
                d[speed][node]=dist;
                for(auto nx:graph[node]){
                    ll nxnode=get<2>(nx),limit=get<1>(nx),len=get<0>(nx);
                    if(limit>=speed)pq.push({dist+len*(fac[10]/speed),speed,nxnode});
                }
            }
        }
    }
    ll ans=9e18,x=1e10;
    __int128 aa=ans,xx=x;
    for(int i=1;i<=10;i++)
        if(d[i][n]<8e18){
            __int128 dd=d[i][n],ff=fac[10];
            aa=min(aa,(dd*xx)/ff);
        }
    printf("%lld.%0*lld",(ll)(aa/xx),9,(ll)(aa%xx)%10ll>=5ll?(ll)(aa%xx)/10ll+1ll:(ll)(aa%xx)/10ll);
    return 0;
}