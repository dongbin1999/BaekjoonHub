#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> graph[501];
bool vis[501];

//음의 사이클이 발생하면 false 리턴. n:정점 개수.
bool bellman_ford(int st,int n){
    if(vis[st])return false;
    vector<ll> dist(n+1,1e18);dist[st]=0,vis[st]=1;
    int loop=n-1;
    while(loop--)
        for(int s=1;s<=n;s++)
            for(auto [nx,cost]:graph[s])
                if(dist[s]!=1e18)
                    dist[nx]=min(dist[nx],dist[s]+cost),vis[nx]=1;

    //한번더 돌아서 값이 갱신되면, 음의 사이클이 존재하는 것.
    for(int s=1;s<=n;s++)
        for(auto [nx,cost]:graph[s])
            if(dist[nx]>dist[s]+cost&&dist[nx]!=1e18)
                return true;

    return false;
}

void solve(){
    int n,m,w;scanf("%d%d%d",&n,&m,&w);
    while(m--){
        int a,b;ll c;
        scanf("%d%d%lld",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    while(w--){
        int a,b;ll c;
        scanf("%d%d%lld",&a,&b,&c);
        graph[a].push_back({b,-c});
    }
    memset(vis,0,sizeof(vis));
    bool ok=0;
    for(int i=1;i<=n;i++)ok|=bellman_ford(i,n);
    printf(ok?"YES\n":"NO\n");
    for(int i=1;i<=n;i++)graph[i].clear();
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}