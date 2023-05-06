#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree,tmp;
vector<bool> cut;
queue<int> q;
int n;
void dfs(int node,int pa){
    if(tree[node].size()==1)cut[node]=1,q.push(node);
    for(auto nx:tree[node])
        if(nx!=pa)dfs(nx,node);
}
void dfs2(int node,int pa){
    if(tree[node].size()!=2||cut[node])return;
    cut[node]=1;
    for(auto nx:tree[node])
        if(nx!=pa)dfs2(nx,node);
}

void cutting(){
    cut.assign(n+1,0);
    tmp.assign(n+1,{});
    for(int i=1;i<=n;i++)if(!tree[i].empty()){dfs(i,i);break;}
    while(!q.empty())
        dfs2(tree[q.front()][0],q.front()),q.pop();
    for(int i=1;i<=n;i++)
        for(auto j:tree[i])
            if(!cut[i]&&!cut[j])tmp[i].push_back(j);
    tree=tmp;
}
int main(){
    scanf("%d",&n);
    tree.assign(n+1,{});
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int m=2;while(m--)cutting();
    for(auto v:tree)if(v.size()>=3)return !printf("NO");
    return !printf("YES");
}