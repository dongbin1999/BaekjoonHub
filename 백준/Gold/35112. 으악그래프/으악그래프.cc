#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> g[100001];
vector<pii> v;
int n,in[100001];
bool cycle(){
    for(int i=1;i<=n;i++)g[i].clear(),in[i]=0;
    for(auto [x,y]:v){
        g[x].push_back(y),g[y].push_back(x);
        in[x]++,in[y]++;
    }
    set<pii> se;
    queue<int> q;
    for(int i=1;i<=n;i++)if(in[i]==1)q.push(i);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto nx:g[x]){
            if(--in[nx]==1)q.push(nx);
            se.insert({min(x,nx),max(x,nx)});
        }
    }
    if(se.size()==v.size())return false;
    for(auto [x,y]:v)if(!se.count({x,y})){
        vector<pii> v1;
        for(auto [x1,y1]:v)if(x1!=x||y1!=y)v1.push_back({x1,y1});
        v=v1;break;
    }
    return true;
}
int main(){
    int m;scanf("%d%d",&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        v.push_back({min(x,y),max(x,y)});
    }
    if(!cycle())return !printf("Yes");
    if(!cycle())return !printf("Yes");
    printf("No");
}