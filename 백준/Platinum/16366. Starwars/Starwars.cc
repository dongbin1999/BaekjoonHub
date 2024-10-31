#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool vis[1000][1000],human[1000];
vector<pii> graph[1000][1000];
vector<pii> edge[21];

int main(){
    int n,w,c,h,m;scanf("%d%d%d%d%d",&n,&w,&c,&h,&m);
    vector<int> a(h),b(m);

    for(auto &x:a)scanf("%d",&x),human[x]=1;
    for(auto &x:b)scanf("%d",&x);
    while(w--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        edge[y].push_back({x,z});
    }
    for(int i=1;i<=c;i++)
        for(auto [s1,e1]:edge[i])for(auto [s2,e2]:edge[i])
            graph[s1][s2].push_back({e1,e2});

    queue<pii> q;
    for(auto x:a)for(int y=0;y<n;y++)
        if(!human[y])vis[x][y]=1,q.push({x,y});
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(auto [nx,ny]:graph[x][y])
            if(!vis[nx][ny])q.push({nx,ny}),vis[nx][ny]=1;
    }
    for(auto x:b)for(auto y:b)if(vis[x][y])return !printf("YES");
    printf("NO");
}