#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<ll,3> tup;
vector<pll> g[2001];
int n,a[2001],idx[2001],sp;
const int sz=1<<11;
ll arr[sz<<1],lazy[sz<<1];

void propagate(int node){
    if(lazy[node]>1e18)return;
    if(node<sz){
        lazy[node<<1]=min(lazy[node<<1],lazy[node]);
        lazy[node<<1|1]=min(lazy[node<<1],lazy[node]);
    }
    arr[node]=min(arr[node],lazy[node]);
    lazy[node]=2e18;
}

void update(int s,int e,ll k,int node=1,int ns=0,int ne=sz-1){
    propagate(node);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[node]=min(lazy[node],k);
        propagate(node);return;
    }
    int mid=(ns+ne)>>1;
    update(s,e,k,node<<1,ns,mid),update(s,e,k,node<<1|1,mid+1,ne);
    arr[node]=min(arr[node<<1],arr[node<<1|1]);
}void update(int i,ll k){update(i,i,k);}

ll query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    propagate(node);
    if(e<ns||ne<s)return 2e18;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return min(query(s,e,node<<1,ns,mid),query(s,e,node<<1|1,mid+1,ne));
}

vector<pll> dijkstra(int s,int r){//s시작 : r=1, e시작 : r=-1 <- 시작점에 더 가까운 정점을 고르기 위해서.
    vector<pll> d(n+1,{2e18,-1});
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,r==1?1:-sp,s});
    while(!pq.empty()){
        //pre:가장 처음으로 운 좋은 경로를 벗어나게 되었을 때, 그 마지막 운 좋은 경로의 정점의 idx.
        auto [dist,pre,cur]=pq.top();pq.pop();
        if(d[cur]<=pll{dist,pre})continue;
        //printf("%d %lld %lld %lld\n",s,dist,pre,cur);
        d[cur]=pll{dist,pre};
        for(auto [nx,cost]:g[cur]){
            ll npre=idx[nx]?idx[nx]*r:pre,ndist=dist+cost;
            if(d[nx]>pll{ndist,npre})pq.push({ndist,npre,nx});
        }
    }
    return d;
}

int main(){
    int m,s,e;scanf("%d%d%d%d",&n,&m,&s,&e);
    vector<tup> edge(m);
    for(auto &[x,y,w]:edge){
        scanf("%lld%lld%lld",&x,&y,&w);
        g[x].push_back({y,w}),g[y].push_back({x,w});
    }
    scanf("%d",&sp);
    set<pii> se;
    for(int i=1;i<=sp;i++){
        scanf("%d",&a[i]);
        if(i>1)se.insert({a[i-1],a[i]});
        idx[a[i]]=i;
    }
    auto sd=dijkstra(s,1),ed=dijkstra(e,-1);
    memset(arr,0x3f,sizeof(arr));
    memset(lazy,0x3f,sizeof(lazy));
    for(auto [x,y,w]:edge){
        if(se.count({x,y})||se.count({y,x}))continue;
        auto [sdist,spre]=sd[x];
        auto [edist,epre]=ed[y];epre*=-1;
        ll distance=sdist+edist+w;
        //printf("%lld %lld %lld: %lld, %lld %lld\n",x,y,w,distance,spre,epre);
        update(spre,epre-1,distance);
        auto [sdist2,spre2]=sd[y];
        auto [edist2,epre2]=ed[x];epre2*=-1;
        distance=sdist2+edist2+w;
        //printf("%lld %lld %lld: %lld, %lld %lld\n",y,x,w,distance,spre2,epre2);
        update(spre2,epre2-1,distance);
    }

    for(int i=1;i<sp;i++){
        ll x=query(i,i);
        printf("%lld\n",x>1e18?-1:x);
    }
}