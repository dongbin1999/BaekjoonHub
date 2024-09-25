#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> graph[100001];
int u[100001],f[100001],l[100001],r[100001],ans[100001],d[100001],vis[100001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}

int main() {
    int n,m,k,q;scanf("%d%d%d%d",&n,&m,&k,&q);
    while(m--){
        int s,e,dist;scanf("%d%d%d",&s,&e,&dist);
        graph[s].push_back({e,dist}),graph[e].push_back({s,dist});
    }
    while(k--){
        int x;scanf("%d",&x);
        f[x]=1;
    }
    vector<pii> v(q);
    for(int i=0;i<q;i++){
        int s,e;scanf("%d%d",&s,&e);
        v[i]={s,e};
    }
    memset(r,0x3f,sizeof(r)),memset(d,0x3f,sizeof(d));
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++)if(f[i])pq.push({0,i});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<=dist)continue;d[cur]=dist;
        for(auto [nx,cost]:graph[cur])
            pq.push({dist+cost,nx});
    }
    vector<pii> di;
    for(int i=1;i<=n;i++)di.push_back({d[i],i});
    sort(di.begin(),di.end(),greater<pii>());
    int it=30;
    while(it--){
        memset(u,-1,sizeof(u)),memset(vis,0,sizeof(vis));
        vector<pii> mid(q);
        for(int i=0;i<q;i++)
            mid[i]={(l[i]+r[i])/2,i};
        sort(mid.begin(),mid.end(),greater<pii>());
        int didx=0;
        vector<int> vv;
        for(auto [val,idx]:mid){
            while(didx<di.size()&&di[didx].first>=val){
                int x=di[didx++].second;
                vis[x]=1;
                for(auto [nx,cost]:graph[x])if(vis[nx])merge(x,nx);
            }
            bool ok=find(v[idx].first)==find(v[idx].second);
            if(ok)ans[idx]=max(ans[idx],val),l[idx]=val+1;
            else r[idx]=val-1;
        }
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
}