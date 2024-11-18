#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> graph[10001];
int d[10001],b[10001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    set<int> se;
    while(m--){
        int s,e;scanf("%d%d",&s,&e);
        graph[s].push_back(e),graph[e].push_back(s);
    }
    for(int i=1;i<=10000;i++)sort(graph[i].begin(),graph[i].end());
    int s,e;scanf("%d%d",&s,&e);
    queue<pii> q;
    memset(d,0x3f,sizeof(d));
    q.push({0,s}),d[s]=0;
    while(!q.empty()){
        auto [pre,cur]=q.front();q.pop();
        for(auto nx:graph[cur])
            if(d[nx]>1e9)q.push({cur,nx}),d[nx]=d[cur]+1,b[nx]=cur;
    }
    int x=e;
    while(x!=s){
        int nx=b[x];
        se.insert(x),x=nx;
    }
    int ans=d[e];
    memset(d,0x3f,sizeof(d));
    q.push({0,e});d[e]=0;
    while(!q.empty()){
        auto [pre,cur]=q.front();q.pop();
        for(auto nx:graph[cur])
            if(se.count(nx))continue;
            else if(d[nx]>1e9)q.push({cur,nx}),d[nx]=d[cur]+1,b[nx]=cur;
    }
    printf("%d",d[s]+ans);
    return 0;
}