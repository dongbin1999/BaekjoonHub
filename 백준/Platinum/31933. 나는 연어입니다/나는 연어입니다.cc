#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
#define idx(x) (upper_bound(comp.begin(),comp.end(),x)-comp.begin()-1)
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
vector<tup> graph[5001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> comp={1,1<<30};
    while(m--){
        int u,v,l,r;scanf("%d%d%d%d",&u,&v,&l,&r);
        //[l,r) 크기가 통과 가능.
        graph[u].push_back({v,l,r});
        graph[v].push_back({u,l,r});
        comp.push_back(l),comp.push_back(r+1);
    }
    UNIQUE(comp);
    map<int,int> ma;
    int k;scanf("%d",&k);
    while(k--){
        int x;scanf("%d",&x);
        ma[idx(x)]++;
    }
    int ans=0;
    for(auto [i,cnt]:ma){
        vector<bool> vis(n+1);
        queue<int> q;q.push(1),vis[1]=1;
        int L=comp[i],R=comp[i+1]-1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto [nx,l,r]:graph[cur]){
                if(vis[nx])continue;
                if(R<l||r<L)continue;
                q.push(nx),vis[nx]=1;
            }
        }
        if(vis[n])ans+=cnt;
    }
    printf("%d",ans);
}