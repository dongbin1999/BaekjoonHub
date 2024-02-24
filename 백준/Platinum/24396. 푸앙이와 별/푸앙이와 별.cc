#include<bits/stdc++.h>
using namespace std;

unordered_set<int> cut[300001];
int d[300001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        cut[a].insert(b),cut[b].insert(a);
    }
    set<int> todo;
    for(int i=2;i<=n;i++)todo.insert(i);
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    queue<pair<int,int>> q;q.push({1,0});
    while(!q.empty()){
        auto [cur,dist]=q.front();q.pop();
        vector<int> del;
        for(auto nx:todo)
            if(!cut[cur].count(nx))
                del.push_back(nx),d[nx]=dist+1,q.push({nx,dist+1});
        for(auto i:del)todo.erase(i);
    }
    for(int i=1;i<=n;i++)printf("%d\n",d[i]>1e9?-1:d[i]);
}