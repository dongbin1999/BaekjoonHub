#include<bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int val[100001];

int go(int node,int pa,int d){
    if(val[node]!=-1)return val[node];
    int ret=d%2?2e9:-2e9;
    for(auto nx:tree[node])if(nx!=pa)
        ret=d%2?min(ret,go(nx,node,d+1)):max(ret,go(nx,node,d+1));
    return val[node]=ret;
}

int main(){
    int n,r;scanf("%d%d",&n,&r);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v),tree[v].push_back(u);
    }
    int l;scanf("%d",&l);
    memset(val,-1,sizeof(val));
    while(l--){
        int k,t;scanf("%d%d",&k,&t);
        val[k]=t;
    }
    go(r,-1,0);
    int q;scanf("%d",&q);
    while(q--){
        int x;scanf("%d",&x);
        printf("%d\n",val[x]);
    }
}