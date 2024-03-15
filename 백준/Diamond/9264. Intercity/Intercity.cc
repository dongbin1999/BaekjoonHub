#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
unordered_set<int> se[500001];
int n,k,a,b;
int A(){
    queue<pii> q;q.push({1,0});
    while(!q.empty()){
        auto [cur,dist]=q.front();q.pop();
        if(cur==n)return dist;
        for(auto nx:se[cur])
            if(dist+a<b)q.push({nx,dist+a});
    }
    return b;
}

int B(){
    unordered_set<int> go;
    for(int i=2;i<=n;i++)go.insert(i);
    queue<pii> q;q.push({1,0});
    while(!q.empty()){
        auto [cur,dist]=q.front();q.pop();
        vector<int> e;
        if(cur==n)return dist;
        for(auto nx:go){
            if(se[cur].count(nx)||se[nx].count(cur))continue;
            if(dist+b<a)e.push_back(nx),q.push({nx,dist+b});
        }
        for(auto i:e)go.erase(go.find(i));
    }
    return a;
}
int main(){
    scanf("%d%d%d%d",&n,&k,&a,&b);
    while(k--){
        int x,y;scanf("%d%d",&x,&y);
        se[x].insert(y);
    }
    printf("%d",a<b?A():B());
    return 0;
}