#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=16;

int depth[1<<sz],sparse[1<<sz][sz],pa[1<<sz];
vector<int>tree[1<<sz];
ll v[1<<sz],ans;

void go(int node=1,int d=0,int parent=0){
    sparse[node][0]=parent,depth[node]=d,pa[node]=parent;
    for(int i=1;i<sz;i++)
        sparse[node][i]=sparse[sparse[node][i-1]][i-1];
    for(int to:tree[node])
        if(parent!=to)go(to,d+1,node);
}

int LCA(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    for(int i=sz-1;i>=0;i--)
        if(depth[sparse[b][i]]>=depth[a])b=sparse[b][i];
    if(a==b)return a;
    for(int i=sz-1;i>=0;i--)
        if(sparse[a][i]!=sparse[b][i])
            a=sparse[a][i],b=sparse[b][i];
    return sparse[a][0];
}

ll go2(int node=1,int parent=0){
    ll sum=v[node];
    for(auto nx:tree[node])
        if(nx!=parent)sum+=go2(nx,node);
    ans=max(ans,sum);
    return sum;
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    while(k--){
        int a,b;scanf("%d%d",&a,&b);
        int lca=LCA(a,b);
        v[a]++,v[b]++,v[lca]--,v[pa[lca]]--;
    }
    go2();
    printf("%lld",ans);
}