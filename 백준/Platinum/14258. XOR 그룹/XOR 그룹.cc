#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
pii go[4]={{1,0},{-1,0},{0,1},{0,-1}};

int u[1000001],vis[1000001];
ll XOR[1000001];

int find(int x){
    if(u[x]<0)return x;
    return u[x]=find(u[x]);
}

bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],XOR[a]^=XOR[b],XOR[b]=0,u[b]=a;
    return true;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(u,-1,sizeof(u));

    vector<pli> v;
    for(int i=0;i<n*m;i++){
        scanf("%lld",&XOR[i]);
        v.push_back({XOR[i],i});
    }
    sort(v.begin(),v.end(),greater<pli>());
    ll tmp=0,ans=0;
    for(int i=0;i<v.size();i++){
        auto [val,idx]=v[i];
        int x=idx/m,y=idx%m;
        set<int> adj;
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy,nidx=nx*m+ny;
            if(nx<0||nx>=n||ny<0||ny>=m||!vis[find(nidx)])continue;
            adj.insert(find(nidx));
        }
        XOR[idx]=val,vis[idx]=1;
        if(adj.empty())tmp+=val;
        else{
            for(auto p:adj)tmp-=XOR[p];
            for(auto p:adj)merge(p,idx);
            tmp+=XOR[find(idx)];
        }
        ans=max(ans,tmp);
    }

    printf("%lld",ans);
    return 0;
}