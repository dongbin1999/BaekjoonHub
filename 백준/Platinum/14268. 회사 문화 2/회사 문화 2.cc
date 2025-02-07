#include <bits/stdc++.h>
using namespace std;
const int sz=1<<17;
vector<int> tree[sz];
int dfsn[sz],out[sz],number=0,arr[sz<<1],lazy[sz<<1];
void dfs(int node=1){
    dfsn[node]=++number;
    for(auto nx:tree[node])dfs(nx);
    out[node]=number;
}

void propagate(int node,int ns,int ne){
    if(!lazy[node])return;
    if(node<sz){
        lazy[node<<1]+=lazy[node];
        lazy[node<<1|1]+=lazy[node];
    }
    arr[node]+=lazy[node]*(ne-ns+1);
    lazy[node]=0;
}

void update(int s,int e,int k,int node=1,int ns=0,int ne=sz-1){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[node]+=k;
        propagate(node,ns,ne);return;
    }
    int mid=(ns+ne)>>1;
    update(s,e,k,node<<1,ns,mid),update(s,e,k,node<<1|1,mid+1,ne);
    arr[node]=arr[node<<1]+arr[node<<1|1];
}

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}int query(int x){return query(x,x);}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int pa;scanf("%d",&pa);
        if(pa!=-1)tree[pa].push_back(i);
    }
    dfs();
    while(m--){
        int c;scanf("%d",&c);
        if(c==1){
            int i,w;scanf("%d%d",&i,&w);
            update(dfsn[i],out[i],w);
        }
        else{
            int i;scanf("%d",&i);
            printf("%d\n",query(dfsn[i]));
        }
    }
    return 0;
}