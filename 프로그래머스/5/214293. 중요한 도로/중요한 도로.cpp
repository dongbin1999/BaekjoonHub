#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef array<ll,3> tup;
typedef array<ll,4> arr;
vector<arr> graph[50001];
int pre[50001];
set<int> shortest[3];
vector<ll> dijkstra(int s,int n,vector<vector<ll>> roads){
    for(int i=1;i<=n;i++)graph[i].clear();
    for(int j=0;j<roads.size();j++){
        auto i=roads[j];ll u=i[0],v=i[1],l=i[2],t=i[3];
        graph[u].push_back({v,l,t,j});
        graph[v].push_back({u,l,t,j});
    }
    ll mx=8e18;mx*=8e18;
    vector<ll> dist(n+1,mx);
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,s,-1});
    while(!pq.empty()){
        auto [d,cur,pre_edge]=pq.top();pq.pop();
        if(dist[cur]<mx)continue;
        dist[cur]=d,pre[cur]=pre_edge;
        for(auto [nx,l,t,i]:graph[cur])
            pq.push({d+l+t,nx,i});
    }
    return dist;
}

vector<int> solution(int n, vector<vector<int>> r) {
    vector<int> answer;vector<bool> need(r.size());
    vector<vector<ll>> roads;
    for(auto i:r)roads.push_back({i[0],i[1],i[2],i[3]});
    //1. t를 줄였을 때 예상 소요 시간이 짧게 변하는 경우: dist(1->x) + dist(y->n) + (x,y)간선의 t를 0으로 만든 값이, dist(1->n)보다 짧은 경우.  
    vector<ll> rev=dijkstra(n,n,roads),d=dijkstra(1,n,roads);
    for(int j=0;j<roads.size();j++){
        auto i=roads[j];ll u=i[0],v=i[1],l=i[2],t=i[3];
        if(d[u]+rev[v]+l<d[n])need[j]=1;
        else if(d[v]+rev[u]+l<d[n])need[j]=1;
    }
    //2. t를 늘렸을 때 예상 소요 시간이 길게 변하는 경우: 여러가지 최단경로에 포함되는 간선들 중에서, 반드시 지나가야하는 간선이 존재하는 경우, 그 간선들 전부.
    int x=n;
    while(pre[x]!=-1){
        shortest[0].insert(pre[x]);
        int u=roads[pre[x]][0],v=roads[pre[x]][1];
        x=x==u?v:u;
    }
    auto roads2=roads;
    for(int i=0;i<roads.size();i++)roads2[i][2]*=2e18,roads2[i][3]*=2e18;
    for(auto i:shortest[0])roads2[i][2]++,roads2[i][3]++;
    dijkstra(1,n,roads2);
    x=n;
    while(pre[x]!=-1){
        shortest[1].insert(pre[x]);
        int u=roads[pre[x]][0],v=roads[pre[x]][1];
        x=x==u?v:u;
    }
    
    auto roads3=roads;
    for(int i=0;i<roads.size();i++)roads3[i][2]*=2e18,roads3[i][3]*=2e18;
    for(auto i:shortest[1])roads3[i][2]++,roads3[i][3]++;
    dijkstra(1,n,roads3);
    x=n;
    while(pre[x]!=-1){
        shortest[2].insert(pre[x]);
        int u=roads[pre[x]][0],v=roads[pre[x]][1];
        x=x==u?v:u;
    }
    
    for(auto i:shortest[0])
        if(shortest[1].count(i)&&shortest[2].count(i))need[i]=1;

    for(int i=0;i<need.size();i++)if(need[i])answer.push_back(i+1);
    if(answer.empty())return {-1};
    return answer;
}