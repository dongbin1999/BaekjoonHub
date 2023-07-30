#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
const int sz=1<<17,psz=2;
const ll base=100001;
const ll mod[psz]={1000000007,1000000009};
int sub[sz],dep[sz],par[sz],top[sz],in[sz],out[sz],dfsnumbering;
ll arr[psz][2][sz*2],lazy[psz][2][sz*2];
vector<int> tree[sz],child[sz];

void propagate(int node,int p,bool b){
    if(!lazy[p][b][node]) return;
    if(node<sz){
        lazy[p][b][node*2]=lazy[p][b][node];
        lazy[p][b][node*2+1]=lazy[p][b][node];
    }
    arr[p][b][node]=lazy[p][b][node];
    lazy[p][b][node]=0;
}

void update(int s,int e,ll val,int node,int ns,int ne,int p,bool b){
    propagate(node,p,b);
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e){
        lazy[p][b][node]=val;
        propagate(node,p,b); return;
    }
    int mid=(ns+ne)/2;
    update(s,e,val,node*2,ns,mid,p,b),update(s,e,val,node*2+1,mid+1,ne,p,b);
    ll a[2]={arr[p][b][node*2],arr[p][b][node*2+1]};
    arr[p][b][node]=b?max(a[0],a[1]):min(a[0],a[1]);
}void update(int s,int e,ll val,int p,bool b){update(s,e,val,1,0,sz-1,p,b);}

ll query(int s,int e,int node,int ns,int ne,int p,bool b){
    propagate(node,p,b);
    if(e<ns||ne<s)return b?0:2e18;
    if(s<=ns&&ne<=e)return arr[p][b][node];
    int mid=(ns+ne)/2;
    ll a[2]={query(s,e,node*2,ns,mid,p,b),query(s,e,node*2+1,mid+1,ne,p,b)};
    return b?max(a[0],a[1]):min(a[0],a[1]);
}ll query(int s,int e,int p,bool b){return query(s,e,1,0,sz-1,p,b);}

void dfs(int cur,int pa){
    sub[cur]=1;
    for(auto go:tree[cur])
        if(go!=pa){
            child[cur].push_back(go),par[go]=cur,dep[go]=dep[cur]+1;
            dfs(go,cur); sub[cur]+=sub[go];
        }
}

void dfs1(int cur){
    for(auto &go:child[cur]){
        dfs1(go);
        if(sub[go]>sub[child[cur][0]])swap(go,child[cur][0]);
    }
}

void dfs2(int cur){
    in[cur]=++dfsnumbering;
    for(auto go:child[cur]){
        top[go]=go==child[cur][0]?top[cur]:go;
        dfs2(go);
    }
    out[cur]=dfsnumbering;
}

bool ok(vector<pii> path){
    for(int p=0;p<psz;p++){
        ll mx=LLONG_MIN,mn=LLONG_MAX;
        for(auto [s,e]:path)
            mn=min(mn,query(s,e,p,0)),mx=max(mx,query(s,e,p,1));
        if(mn!=mx)return false;
    }
    return true;
}

int pathlen(vector<pii> v){int ret=0;for(auto [s,e]:v)ret+=e-s+1;return ret;}

vector<pii> path(int a,int b){
    vector<pii> v;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        int head=top[a];
        v.push_back({in[head],in[a]});
        a=par[head];
    }
    if(dep[a]>dep[b])swap(a,b);
    v.push_back({in[a],in[b]});
    return v;
}

int main(){
    int n,f;scanf("%d%d",&n,&f);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,1),dfs1(1),dfs2(1);
    vector<tup> v(f);
    for(int i=0;i<f;i++){
        int a,b;scanf("%d%d",&a,&b);
        v[i]={pathlen(path(a,b)),a,b};
    }
    sort(v.begin(),v.end(),greater<tup>());
    ll pathnum=0;
    for(auto [len,a,b]:v){
        vector<pii> x=path(a,b);
        ++pathnum;
        if(!ok(x)) return !printf("No");
        for(int p=0;p<psz;p++){
            ll hash=query(in[a],in[a],p,0);
            hash=(hash*base+pathnum)%mod[p];
            for(auto [s,e]:x)
                update(s,e,hash,p,0),update(s,e,hash,p,1);
        }
    }
    printf("Yes");
    return 0;
}