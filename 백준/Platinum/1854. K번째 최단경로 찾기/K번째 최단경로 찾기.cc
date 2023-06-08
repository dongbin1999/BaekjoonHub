#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> graph[1001];
vector<int> dist[1001];
void dijkstra(int n,int k){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [cost,node]=pq.top();pq.pop();
        if(dist[node].size()>=k) continue;
        dist[node].push_back(cost);
        for(auto [nx,add]:graph[node])
            pq.push({cost+add,nx});
    }
    for(int i=1;i<=n;i++){
        if(dist[i].size()<k)printf("-1\n");
        else printf("%d\n",dist[i][k-1]);
    }
}

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    while(m--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    dijkstra(n,k);
    return 0;
}