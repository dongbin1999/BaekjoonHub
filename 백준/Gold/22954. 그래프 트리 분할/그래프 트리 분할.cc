#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> graph[100001];
int group_num,vis[100001];
vector<vector<int>> group_nodes,group_edges,group_leafs;

void go(int node){
    vis[node]=1,group_nodes[group_num].push_back(node);
    bool leaf=1;
    for(auto [nx,edge_num]:graph[node]){
        if(vis[nx])continue;
        group_edges[group_num].push_back(edge_num);
        go(nx);
        leaf=0;
    }
    if(leaf)group_leafs[group_num].push_back(node);
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        graph[x].push_back({y,i});
        graph[y].push_back({x,i});
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        group_nodes.push_back({}),group_edges.push_back({}),group_leafs.push_back({});
        go(i);
        group_num++;
    }
    if(group_num>2||n<=2)printf("-1");
    else if(group_num==2){
        if(group_nodes[0].size()==group_nodes[1].size())return !printf("-1");
        printf("%d %d\n",group_nodes[0].size(),group_nodes[1].size());
        for(auto i:group_nodes[0])printf("%d ",i);
        printf("\n");
        for(auto i:group_edges[0])printf("%d ",i);
        printf("\n");
        for(auto i:group_nodes[1])printf("%d ",i);
        printf("\n");
        for(auto i:group_edges[1])printf("%d ",i);
    }
    else{
        printf("%d %d\n",group_nodes[0].size()-1,1);
        //leafnode 하나 지우기.
        int leaf=group_leafs[0].back();
        unordered_set<int> leaf_edges;
        for(auto [node,edge]:graph[leaf])leaf_edges.insert(edge);

        for(auto i:group_nodes[0])if(i!=leaf)printf("%d ",i);
        printf("\n");
        for(auto i:group_edges[0])if(!leaf_edges.count(i))printf("%d ",i);
        printf("\n");
        printf("%d\n",leaf);
    }
}