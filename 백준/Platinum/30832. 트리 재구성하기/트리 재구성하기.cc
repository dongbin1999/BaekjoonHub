#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
vector<int> tree[2][1001];

vector<tup> ans;
void dfs1(int node=1,int p=1){
    if(p!=1)ans.push_back({node,p,1});
    for(auto nx:tree[0][node])
        if(p!=nx)dfs1(nx,node);
}
void dfs2(int node=1,int p=1){
    for(auto nx:tree[1][node])
        if(p!=nx)dfs2(nx,node);
    if(p!=1)ans.push_back({node,1,p});
}

int main() {
    int n;scanf("%d",&n);
    for(int t=0;t<2;t++)for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[t][u].push_back(v),tree[t][v].push_back(u);
    }
    dfs1();
    dfs2();
    printf("%d\n",ans.size());
    for(auto [a,b,c]:ans)printf("%d %d %d\n",a,b,c);
}