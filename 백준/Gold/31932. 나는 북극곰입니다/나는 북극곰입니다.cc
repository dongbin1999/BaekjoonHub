#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
typedef pair<int,int> pii;
vector<tup> graph[100001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int u,v,d,t;scanf("%d%d%d%d",&u,&v,&d,&t);
        graph[u].push_back({v,d,t});
        graph[v].push_back({u,d,t});
    }
    int l=0,r=1e9,mid,ans=-1;
    while(l<=r){
        mid=l+r>>1;
        vector<int> dist(n+1,2e9);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({mid,1});
        while(!pq.empty()){
            auto [d,cur]=pq.top();pq.pop();
            if(dist[cur]<2e9)continue;
            dist[cur]=d;
            for(auto [nx,cost,t]:graph[cur])
                if(d+cost<=t)pq.push({d+cost,nx});
        }
        if(dist[n]<2e9)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
}