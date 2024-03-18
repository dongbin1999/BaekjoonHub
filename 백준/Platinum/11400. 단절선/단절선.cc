#include<bits/stdc++.h>
using namespace std;
const int mx=100000;
typedef pair<int,int> pii;

vector<int> graph[mx+1];
int dfsn[mx+1],dfsnumber;
vector<pii> cut;

int dfs(int node,int pa){
    int top=dfsn[node]=++dfsnumber;
    for(auto nx:graph[node]){
        if(nx==pa)continue;
        if(dfsn[nx]){//방문한 적 있음
            top=min(top,dfsn[nx]);
            continue;
        }
        int pre=dfs(nx,node);
        if(pre>dfsn[node])cut.push_back({min(node,nx),max(node,nx)});
        top=min(top,pre);
    }
    return top;
}

int main(){
    int v,e;scanf("%d%d",&v,&e);
    while(e--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b),graph[b].push_back(a);
    }

    for(int i=1;i<=v;i++)
        if(!dfsn[i])dfs(i,i);
    sort(cut.begin(),cut.end());
    printf("%d\n",cut.size());
    for(auto [a,b]:cut)printf("%d %d\n",a,b);
}