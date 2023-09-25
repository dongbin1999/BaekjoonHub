#include <bits/stdc++.h>
using namespace std;
vector<int> v[101],r[101];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        v[a].push_back(b);
        r[b].push_back(a);
    }
    map<int,int> vis,se;
    for(int i=1;i<=n;i++){
        vis.clear(),se.clear();
        queue<int> q;q.push(i),vis[i]=1,se[i]=1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto nx:v[cur])
                if(!vis[nx])vis[nx]=1,se[nx]=1,q.push(nx);
        }
        vis.clear();
        q.push(i),vis[i]=1,se[i]=1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto nx:r[cur])
                if(!vis[nx])vis[nx]=1,se[nx]=1,q.push(nx);
        }
        printf("%d\n",n-se.size());
    }
    return 0;
}