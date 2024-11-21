#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> tree[50001];
pll ans;
pll dfs(ll cur,ll pa){
    ll x=1,y=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pll parent;
    for(auto [nx,cost]:tree[cur]){
        if(nx==pa)parent={nx,cost};
        else {
            pq.push(dfs(nx,cur));
            while(pq.size()>2)pq.pop();
        }
    }
    priority_queue<pll> pq2;
    while(!pq.empty())pq2.push(pq.top()),pq.pop();
    if(!pq2.empty()){
        auto [cnt,cost]=pq2.top();pq2.pop();
        x+=cnt,y+=cost;
        ans=max(ans,{x,y});
    }
    if(!pq2.empty()){
        auto [cnt,cost]=pq2.top();pq2.pop();
        ans=max(ans,{x+cnt,y+cost});
    }
    return {x,y-parent.second};
}

pll p;
void f(int cur,int pa=-1,int d=0){
    p=max(p,{d,cur});
    for(auto [nx,cost]:tree[cur])
        if(nx!=pa)f(nx,cur);
}
int main(){
    ll n,t;scanf("%lld%lld",&n,&t);
    for(int i=1;i<n;i++){
        ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        tree[a].push_back({b,c}),tree[b].push_back({a,c});
    }
    f(1);
    dfs(p.second,-1);
    ll a=-ans.second;
    printf("%lld",(a+t-1)/t);
}