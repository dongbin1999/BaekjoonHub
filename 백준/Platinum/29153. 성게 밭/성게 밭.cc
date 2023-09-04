#include <bits/stdc++.h>
using namespace std;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());

vector<int> g[15001],graph[15001],a,b;
int black[15001],white[15001],bidx[15001],widx[15001],bn,wn,vis[15001],chk[15001];

bool BM(int cur){
    vis[cur]=true;
    for(int x:graph[black[cur]]){
        int go=widx[x];
        if(b[go]==-1||!vis[b[go]]&&BM(b[go])){
            a[cur]=go,b[go]=cur;
            return true;
        }
    }
    return false;
}

void color(int node,int c=0){
    chk[node]=1;
    if(c)white[wn]=node,widx[node]=wn++;
    else black[bn]=node,bidx[node]=bn++;
    for(auto nx:graph[node])
        if(!chk[nx])color(nx,!c);
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    set<int> center;
    for(int i=1;i<=n;i++)
        if(g[i].size()>2)center.insert(i);
        else if(g[i].size()==2)
            graph[g[i][0]].push_back(g[i][1]),graph[g[i][1]].push_back(g[i][0]);
    for(int i=1;i<=n;i++)UNIQUE(graph[i]);
    int ans=center.size();
    for(int i=1;i<=n;i++){
        if(!center.count(i)||chk[i])continue;
        wn=0,bn=0;color(i);
        a.assign(bn,-1),b.assign(wn,-1);
        for(int j=0;j<bn;j++){
            fill(vis,vis+bn,0);
            if(BM(j))ans--;
        }
    }
    printf("%d",ans);
    return 0;
}