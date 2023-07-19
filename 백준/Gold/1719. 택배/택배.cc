#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;

int ans[201][201],dist[201][201];
vector<pii> graph[201];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(dist,0x3f,sizeof(dist));
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    while(m--){
        int s,e,v;scanf("%d%d%d",&s,&e,&v);
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    for(int s=1;s<=n;s++){
        for(auto [n,v]:graph[s])
            pq.push({v,n,n});
        while(!pq.empty()){
            auto [d,cur,first]=pq.top();pq.pop();
            if(dist[s][cur]<1e9)continue;
            dist[s][cur]=d,ans[s][cur]=first;
            for(auto [nx,cost]:graph[cur])
                pq.push({d+cost,nx,first});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(i==j)printf("- ");
            else printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}