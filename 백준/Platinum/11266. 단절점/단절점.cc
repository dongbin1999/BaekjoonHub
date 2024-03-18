#include<bits/stdc++.h>
using namespace std;
const int mx=10000;

vector<int> graph[mx+1];
int dfsn[mx+1],dfsnumber,cut[mx+1];

int dfs(int node,bool root=0){
    int top=dfsn[node]=++dfsnumber,child=0;
    for(auto nx:graph[node]){
        if(dfsn[nx]){//방문한 적 있음
            top=min(top,dfsn[nx]);
            continue;
        }
        child++;
        int pre=dfs(nx);
        if(!root&&pre>=dfsn[node])cut[node]=1;
        top=min(top,pre);
    }
    if(root)cut[node]=child>1;
    return top;
}

int main(){
    int v,e;scanf("%d%d",&v,&e);
    while(e--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b),graph[b].push_back(a);
    }
    vector<int> ans;
    for(int i=1;i<=v;i++){
        if(!dfsn[i])dfs(i,1);
        if(cut[i])ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}