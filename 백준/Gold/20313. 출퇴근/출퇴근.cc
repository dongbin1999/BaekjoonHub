#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef array<ll,3> arr;
ll d[101][1001],c[101][2001];
vector<pll> g[1001];

int main(){
    int n,m,a,b;scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,i}),g[v].push_back({u,i}),c[0][i]=w;
    }
    int k;scanf("%d",&k);
    for(int i=1;i<=k;i++)
        for(int j=0;j<m;j++){
            int w;scanf("%d",&w);
            c[i][j]=w;
        }
    memset(d,0x3f,sizeof(d));
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    pq.push({0,0,a});
    while(!pq.empty()){
        auto [dist,magic,cur]=pq.top();pq.pop();
        if(d[magic][cur]<=dist)continue;d[magic][cur]=dist;
        if(magic<k&&d[magic+1][cur]>dist)pq.push({dist,magic+1,cur});
        for(auto [nx,edge]:g[cur]){
            ll nd=dist+c[magic][edge];
            if(d[magic][nx]>nd)pq.push({nd,magic,nx});
        }
    }
    ll ans=2e18;
    for(int i=0;i<=k;i++)ans=min(ans,d[i][b]);
    printf("%lld",ans);
}