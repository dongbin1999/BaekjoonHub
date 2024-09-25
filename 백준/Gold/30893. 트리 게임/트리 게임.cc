#include <bits/stdc++.h>
using namespace std;
 
vector<int> tree[100001];
int pa[100001];
 
void dfs(int node,int parent=-1){
    pa[node]=parent;
    for(auto nx:tree[node])
        if(nx!=parent)dfs(nx,node);
}
 
int main(){
    int n,s,e;scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    dfs(s);
    vector<int> path;
    do{
        e=pa[e],path.push_back(e);
    }while(e!=s);
    reverse(path.begin(),path.end());
 
    bool turn=0;
    for(auto node:path){
        int child=tree[node].size();
        if(node!=s)child--;
        if(turn%2 && child!=1){
            printf("Second");
            return 0;
        }
        turn^=1;
    }
    printf("First");
    return 0;
}