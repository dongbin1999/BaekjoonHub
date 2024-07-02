#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef array<ll,3> tup;

vector<pil> graph[200001];
vector<int> p[100001];
ll dist[3][200001];
vector<int> go[200001];
bool S[200001];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    while(m--){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        graph[u].push_back({v,w});
    }
    set<int> se;
    for(int i=1;i<=k;i++){
        int s;scanf("%d",&s);
        while(s--){
            int x;scanf("%d",&x);
            p[i].push_back(x),se.insert(x);
        }
        S[p[i][0]]=1;
        for(int j=0;j<p[i].size()-1;j++)go[p[i][j]].push_back(p[i][j+1]);
    }
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,1,S[1]});memset(dist,0x3f,sizeof(dist));
    while(!pq.empty()){
        auto [d,cur,b]=pq.top();pq.pop();
        if(dist[b][cur]<1e18)continue;
        dist[b][cur]=d;
        if(b==1){
            for(auto [nx,cost]:graph[cur]){
                ll nb;
                if(S[nx])nb=1;
                else if(!go[cur].empty()&&go[cur].back()==nx){
                    if(go[nx].empty())nb=2;
                    else nb=1;
                }
                else nb=0;
                pq.push({d+cost,nx,nb});
            }
        }
        else if(b==2){
            for(auto [nx,cost]:graph[cur])
                pq.push({d+cost,nx,b});
        }
        else{
            for(auto [nx,cost]:graph[cur])
                pq.push({d+cost,nx,S[nx]});
        }
    }
    for(int i=1;i<=n;i++){
        ll ans=min(dist[0][i],dist[1][i]);
        printf("%lld ",ans<1e18?ans:-1);
    }
}