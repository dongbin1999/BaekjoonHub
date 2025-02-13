#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
int ans,vis[1001];
void go(int x,int c=1){
    vis[x]=c;
    for(auto nx:graph[x]){
        if(vis[nx]==c)ans=0;
        if(!vis[nx])go(nx,3-c);
    }
}
void solve(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)graph[i].clear(),vis[i]=0;
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b),graph[b].push_back(a);
    }
    ans=1;
    for(int i=1;i<=n;i++)
        if(!vis[i])go(i);
    printf(ans?"possible\n":"impossible\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}