#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int u[200001],vis[200001],ok,n;
int find(int x){
    return u[x]<0?x:u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}
vector<int> tree[200001],graph[200001];

void dfs(int cur,int pa){
    vis[cur]=1;
    for(auto nx:tree[cur]){
        if(nx==pa)continue;
        if(!merge(nx,cur)){ok=0;return;}
        dfs(nx,cur);
    }
}

void check(){
    memset(vis,0,sizeof(vis));
    memset(u,-1,sizeof(u)); ok=1;
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i,i);
}

int d[200001];

int main(){
    int m,k;scanf("%d%d%d",&n,&m,&k);
    vector<pii> v(m);
    for(auto &[a,b]:v){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b),graph[b].push_back(a);
    }
    memset(d,0x3f,sizeof(d));
    queue<int> q;
    while(k--){
        int e;scanf("%d",&e);
        d[e]=1,q.push(e);
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:graph[cur])
            if(d[nx]>1e9)d[nx]=d[cur]+1,q.push(nx);
    }
    int l=1,r=m,mid,ans=m;
    while(l<=r){
        mid=(l+r)/2;
        for(int i=1;i<=n;i++)tree[i].clear();
        for(auto [a,b]:v)
            if(d[a]>mid&&d[b]>mid)
                tree[a].push_back(b),tree[b].push_back(a);
        check();
        if(ok)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}