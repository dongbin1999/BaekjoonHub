#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];

int main() {
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(auto &i:graph)sort(i.begin(),i.end(),[](int a,int b){return graph[a].size()<graph[b].size();});
    int s=1;
    for(int i=2;i<=n;i++)if(graph[s].size()>graph[i].size())s=i;
    deque<int> v={s};
    vector<int> vis(n+1);vis[s]=1;
    while(1){
        int idx=0,x=v.back();
        while(vis[graph[x][idx]])idx++;
        v.push_back(graph[x][idx]),vis[graph[x][idx]]=1;
        if(v.size()==n)break;
        idx=0,x=v.front();
        while(vis[graph[x][idx]])idx++;
        v.push_front(graph[x][idx]),vis[graph[x][idx]]=1;
        if(v.size()==n)break;
    }
    printf("0\n");
    for(auto i:v)printf("%d ",i);
}