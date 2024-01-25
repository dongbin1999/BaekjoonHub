#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,long> pil;
typedef tuple<ll,ll,int> tup;

vector<pil> graph[100001];

int main() {
    int n,m;ll x;scanf("%d%d%lld",&n,&m,&x);
    vector<ll> h(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
    while(m--){
        int a,b;ll c;scanf("%d%d%lld",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    vector<ll> dist(n+1,2e18);
    pq.push({0,-x,1});
    while(!pq.empty()){
        auto [d,w,node]=pq.top();pq.pop();
        if(dist[node]<1e18)continue;
        dist[node]=d;
        //printf("%lld %lld %d\n",d,w,node);
        if(node==n)return !printf("%lld",d+h[n]+w);
        for(auto [nx,cost]:graph[node]){
            if(h[node]<cost)continue;
            ll add,nw;
            if(abs(w)-cost>h[nx])add=cost+(abs(w)-cost-h[nx]),nw=-h[nx];
            else add=max(0ll,cost+w)+cost,nw=min(0ll,w+cost);
            pq.push({d+add,nw,nx});
        }
    }
    printf("-1");
}