#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;

vector<pii> g[30001];

int main(){
    int m,n,k,v,w;scanf("%d%d%d%d%d",&m,&n,&k,&v,&w);
    while(m--){
        int x,y,c;scanf("%d%d%d",&x,&y,&c);
        g[x].push_back({y,c});
    }
    set<tup> forbid;
    while(k--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        forbid.insert({x,y,z});
    }
    map<pii,int> d;
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,v,v});
    while(!pq.empty()){
        auto [dist,prev,cur]=pq.top();pq.pop();
        if(d.count({prev,cur}))continue;
        d[{prev,cur}]=dist;
        if(cur==w)return !printf("%d",dist);
        for(auto [nx,cost]:g[cur]){
            if(forbid.count({prev,cur,nx}))continue;
            if(d.count({cur,nx}))continue;
            pq.push({dist+cost,cur,nx});
        }
    }
    printf("-1");
    return 0;
}
