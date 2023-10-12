#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2001];
bool ans;

void dfs(int node,set<int> &v){
    v.insert(node);
    if(v.size()>=5){
        ans=1;return;
    }
    for(auto nx:graph[node])
        if(!v.count(nx))dfs(nx,v);
    v.erase(v.find(node));
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    set<int>se;
    for(int i=1;i<=n;i++)if(!ans)dfs(i,se);
    printf("%d",ans);
    return 0;
}