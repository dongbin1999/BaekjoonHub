#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;ll s;scanf("%d%lld",&n,&s);
    map<ll,vector<ll>> v;
    set<ll> se;
    while(n--){
        ll y,h;scanf("%lld%lld",&y,&h);
        se.insert(y);
        v[y].push_back(h);
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    unordered_map<ll,ll> d;
    pq.push({0,0});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d.count(cur))continue;
        d[cur]=dist;
        if(cur==s)return !printf("%lld",dist);
        auto it=se.lower_bound(cur);
        if(it!=se.begin())//아래에 트램펄린이 있음.
            it--,pq.push({cur-*it+dist,*it});
        for(auto h:v[cur]){
            ll add=min(s-cur,h);
            pq.push({dist+add,cur+add});
        }
    }
    printf("Ducks can't fly");
}