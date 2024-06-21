#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,3> tup;
vector<int> tree[200001];
ll h[200001],sum[200001];
vector<tup> ans;

ll go(int node=1,int pa=-1){
    ll ret=0;
    for(auto nx:tree[node])
        if(nx!=pa)ret+=go(nx,node);
    return sum[node]=ret+h[node];
}

void dfs(int node=1,int pa=-1){
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        if(sum[nx]>=0)dfs(nx,node);
    }
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        if(sum[nx]<0){
            ans.push_back({node,nx,-sum[nx]});
            dfs(nx,node);
        }
    }
    if(sum[node]>0&&pa!=-1)ans.push_back({node,pa,sum[node]});
}

int main(){
    int n;scanf("%d",&n);
    ll x=0;
    for(int i=1;i<=n;i++)scanf("%lld",&h[i]),x+=h[i];
    for(int i=1;i<=n;i++)h[i]-=x/n;
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go(),dfs();
    printf("%d\n",ans.size());
    for(auto [from,to,val]:ans)printf("%lld %lld %lld\n",from,to,val);
    return 0;
}