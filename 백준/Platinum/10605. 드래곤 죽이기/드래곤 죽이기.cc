#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void solve(int n,int m,int k){
    vector<int> vis(n+1,0);
    vector<vector<int>> graph(n+1);
    vector<vector<pii>>dragon(n+1);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b);graph[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        int C,S,N;scanf("%d%d%d",&C,&S,&N);
        dragon[C].push_back({N,S});
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vector<pii> d;
        queue<int> q;q.push(i);vis[i]=1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto x:dragon[cur])d.push_back(x);
            for(auto nx:graph[cur])
                if(!vis[nx])vis[nx]=1,q.push(nx);
        }
        sort(d.begin(),d.end(),greater<pii>());
        int add=0;
        vector<int> mx_reverse(d.size()+1);
        for(int j=d.size()-1;j>=0;j--)mx_reverse[j]=max(mx_reverse[j+1],d[j].first);
        for(int j=0;j<d.size();j++){
            if(add>d[j].first)break;
            add=min(add+d[j].second,d[j].first+1);
        }
        ans+=add;
    }
    printf("%d\n",ans);
}

int main(){
    while(1){
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        if(!n)break;
        solve(n,m,k);
    }
    return 0;
}