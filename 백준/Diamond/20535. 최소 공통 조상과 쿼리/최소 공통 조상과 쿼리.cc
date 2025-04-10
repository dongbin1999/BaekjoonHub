#include<bits/stdc++.h>
using namespace std;
const int sz=19;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,3> arr;

vector<int> tree[1<<sz];
int depth[1<<sz],sparse[1<<sz][sz];
int dfsnumber,dfsn[1<<sz];

void go(int node=1,int d=0,int parent=1){
    dfsn[node]=++dfsnumber;
    sparse[node][0]=parent,depth[node]=d;
    for(int i=1;i<sz;i++)sparse[node][i]=sparse[sparse[node][i-1]][i-1];
    for(int to:tree[node])if(parent!=to)go(to,d+1,node);
}
int LCA(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    for(int i=sz-1;i>=0;i--)if(depth[sparse[b][i]]>=depth[a])b=sparse[b][i];
    if(a==b)return a;
    for(int i=sz-1;i>=0;i--)
        if(sparse[a][i]!=sparse[b][i])
            a=sparse[a][i],b=sparse[b][i];
    return sparse[a][0];
}

ll u[1<<sz];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    u[x]+=u[y],u[y]=x;
    return 1;
}

void init(vector<pii> &v){for(auto [x,y]:v)u[y]=-1;}

void solve(){
    int k;scanf("%d",&k);
    memset(u,-1,sizeof(int)*(k+1));
    vector<pii> v(k);
    for(auto &[x,y]:v)scanf("%d",&y),x=dfsn[y];
    sort(v.begin(),v.end());

    vector<arr> vv;
    for(int i=1;i<k;i++){
        int x=v[i-1].second,y=v[i].second;
        vv.push_back({depth[LCA(x,y)],x,y});
    }
    sort(vv.begin(),vv.end(),greater<arr>());
    ll ans=0;
    for(auto [d,x,y]:vv){
        x=find(x),y=find(y);
        ans+=-u[y]*-u[x]*d;
        merge(x,y);
    }
    printf("%lld\n",ans);
    init(v);
}

int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        int p;scanf("%d",&p);
        tree[p].push_back(i);tree[i].push_back(p);
    }
    go();
    memset(u,-1,sizeof(u));
    while(q--)solve();
}