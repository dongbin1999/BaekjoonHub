#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> graph[40001];

vector<int> dijkstra(int n,int s,int c){
    vector<int> d(n+1,2e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<2e9)continue;d[cur]=dist;
        for(auto nx:graph[cur])
            pq.push({dist+c,nx});
    }
    return d;
}

int main(){
    int b,e,p,n,m;scanf("%d%d%d%d%d",&b,&e,&p,&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        graph[x].push_back(y),graph[y].push_back(x);
    }
    vector<int> A=dijkstra(n,1,b),B=dijkstra(n,2,e),C=dijkstra(n,n,p);
    int ans=2e9;
    for(int i=1;i<=n;i++)ans=min(ans,A[i]+B[i]+C[i]);
    printf("%d",ans);
}