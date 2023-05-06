#include <bits/stdc++.h>
using namespace std;
vector<set<int>> tree;
vector<bool> leaf;
int n;
void dfs(int node,int pa){
    leaf[node]=tree[node].size()==1;
    if(tree[node].size()==2){
        auto it=tree[node].begin();
        int x=*it; it++;int y=*it;
        tree[x].erase(find(tree[x].begin(),tree[x].end(),node));
        tree[y].erase(find(tree[y].begin(),tree[y].end(),node));
        tree[x].insert(y);
        tree[y].insert(x);
        tree[node].clear();
        x==pa?dfs(y,x):dfs(x,y);
        return;
    }
    set<int> tmp=tree[node];
    for(auto nx:tmp)
        if(nx!=pa)dfs(nx,node);
}

void refactoring(){
    leaf.assign(n+1,0);
    for(int i=1;i<=n;i++)if(tree[i].size()==1){dfs(i,i);break;}
    for(int i=1;i<=n;i++)
        if(leaf[i]){
            int x=*tree[i].begin();
            auto it=find(tree[x].begin(),tree[x].end(),i);
            if(it!=tree[x].end())tree[x].erase(it);
            tree[i].clear();
        }
}
int main(){
    scanf("%d",&n);
    tree.assign(n+1,{});
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].insert(b);
        tree[b].insert(a);
    }
    int m=2;while(m--)refactoring();
    for(auto v:tree)if(v.size()>=3)return !printf("NO");
    return !printf("YES");
}