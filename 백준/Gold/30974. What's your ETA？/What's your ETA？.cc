#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

ll d[400001];
vector<pii> graph[400001];
int p[10000001];


int main(){
    p[1]=1;
    for(int i=2;i<=10000000;i++)
        if(!p[i])for(int j=i;j<=10000000;j+=i)
            if(!p[j])p[j]=i;
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
    while(m--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        ll x=d[u]+d[v];
        if(p[x]!=x)continue;
        graph[u].push_back({v,w}),graph[v].push_back({u,w});
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    memset(d,0x3f,sizeof(d));
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<2e18)continue;
        d[cur]=dist;
        if(cur==n)return !printf("%lld",dist);
        for(auto [nx,cost]:graph[cur])
            pq.push({dist+cost,nx});
    }
    printf("Now where are you?");
    return 0;
}