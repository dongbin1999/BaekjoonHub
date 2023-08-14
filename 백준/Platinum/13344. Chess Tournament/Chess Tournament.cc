#include <bits/stdc++.h>
using namespace std;

vector<int> graph[50001];
int u[50001],in[50001],vis[50001];
int find(int x){
    if(u[x]<0)return x;
    return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(u,-1,sizeof(u));
    vector<tuple<int,int,int>> v;
    while(m--){
        int a,b;char c;
        scanf(" %d %c %d",&a,&c,&b);
        v.push_back({a,c,b});
        if(c=='=')merge(a,b);
    }
    for(auto [a,c,b]:v){
        a=find(a),b=find(b);
        if(a==b&&c!='=')return !printf("inconsistent");
        if(c=='>')graph[a].push_back(b),in[b]++;
        if(c=='<')graph[b].push_back(a),in[a]++;
    }
    int ans=0;
    for(int i=0;i<n;i++)if(i==find(i))ans++;
    queue<int> q;
    for(int i=0;i<n;i++)if(i==find(i)&&!in[i])q.push(i),ans--;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:graph[cur]){
            in[nx]--;
            if(!in[nx])q.push(nx),ans--;
        }
    }
    printf(ans?"inconsistent":"consistent");
    return 0;
}