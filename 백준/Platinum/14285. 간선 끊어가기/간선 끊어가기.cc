#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> graph[5001];
int d[5001],r[5001];
map<pii,int> ma;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    int sum=0;
    memset(d,0x3f,sizeof(d));
    memset(r,0x3f,sizeof(r));
    while(m--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
        ma[{a,b}]=ma[{b,a}]=c;
        sum+=c;
    }
    int s,t;scanf("%d%d",&s,&t);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<1e9)continue;
        d[cur]=dist;
        for(auto [nx,cost]:graph[cur])
            pq.push({dist+cost,nx});
    }
    pq.push({0,t});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(r[cur]<1e9)continue;
        r[cur]=dist;
        for(auto [nx,cost]:graph[cur])
            pq.push({dist+cost,nx});
    }
    int ans=2e9;
    for(auto[a,b]:ma){
        auto[x,y]=a;
        ans=min(ans,d[x]+r[y]);
    }
    printf("%d",sum-ans);
}