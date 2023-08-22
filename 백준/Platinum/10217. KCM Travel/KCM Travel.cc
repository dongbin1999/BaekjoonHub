#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;

int dist[10001][101],vis[10001][101];
vector<tup> graph[101];

void solve(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    while(k--){
        int u,v,c,d;scanf("%d%d%d%d",&u,&v,&c,&d);
        graph[u].push_back({d,c,v});
    }
    for(int i=1;i<=n;i++)sort(graph[i].begin(),graph[i].end());
    memset(dist,0x3f,sizeof(dist));
    priority_queue<tup,vector<tup>,greater<tup>> pq; pq.push({0,0,1});
    while(!pq.empty()){
        auto [d,c,node]=pq.top();pq.pop();
        if(vis[c][node])continue;
        if(node==n){printf("%d\n",d);return;}
        vis[c][node]=1;
        for(auto [dd,dc,nx]:graph[node]){
            if(c+dc>m||dd+d>=dist[c+dc][nx])continue;
            for(int i=c+dc;i<=m&&dist[i][nx]>dd+d;i++)dist[i][nx]=dd+d;
            pq.push({d+dd,c+dc,nx});
        }
    }
    printf("Poor KCM\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}