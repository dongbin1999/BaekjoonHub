#include<bits/stdc++.h>
using namespace std;
vector<int> tree[300001];
int pa[300001],dep[300001];
void go(int cur,int p=-1,int d=0){
    pa[cur]=p,dep[cur]=d;
    for(auto nx:tree[cur])
        if(p!=nx)go(nx,cur,d+1);
}
int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go(1);
    vector<int> vis(n+1);
    queue<int> q;vis[a]=vis[b]=1;
    if(dep[a]>dep[b]&&!vis[pa[a]])q.push(pa[a]),vis[pa[a]]=1;
    else if(!vis[pa[b]])vis[pa[b]]=1,q.push(pa[b]);
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(auto nx:tree[cur])
            if(!vis[nx])q.push(nx),vis[nx]=1;
    }
    printf("%d",accumulate(vis.begin(),vis.end(),-2));
}