#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001],d[500001];
vector<int> g[500001];
int main(){
    int n,m,x,y;scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    while(m--){
        int s,e;scanf("%d%d",&s,&e);
        g[s].push_back(e),g[e].push_back(s);
    }
    memset(d,-1,sizeof(d));
    queue<int> q;
    while(y--){
        int b;scanf("%d",&b);
        q.push(b),d[b]=0;
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:g[cur])if(d[nx]==-1)d[nx]=d[cur]+1,q.push(nx);
    }
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++)pq.push(a[i]*d[i]<0?2e18:a[i]*d[i]);
    ll ans=0;
    while(x--){
        if(pq.top()>1e18)return !printf("-1");
        ans+=pq.top(),pq.pop();
    }
    printf("%lld\n",ans);
}