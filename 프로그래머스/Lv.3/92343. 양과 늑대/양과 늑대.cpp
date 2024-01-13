#include <bits/stdc++.h>
using namespace std;

vector<int> tree[20];

// int ans=0;
// void dfs(int node,int pre,int sheep,int wolf,vector<int>& info){
//     ans=max(ans,sheep);
//     for(auto nx:tree[node])
//         if(nx!=pre&&sheep+!info[nx]>wolf+info[nx])
//             dfs(nx,node,sheep+!info[nx],wolf+info[nx],info);
// }

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto i:edges){
        tree[i[0]].push_back(i[1]);
        tree[i[1]].push_back(i[0]);
    }
    map<set<int>,int> vis;
    queue<pair<set<int>,pair<int,int>>> q;
    vis[{0}]=1,q.push({{0},{1,0}});
    while(!q.empty()){
        auto [se,sw]=q.front();q.pop();
        auto [sheep,wolf]=sw;
        for(auto node:se)for(auto nx:tree[node])
            if(!se.count(nx)){
                int ns=sheep+!info[nx],nw=wolf+info[nx];
                set<int> nset=se;nset.insert(nx);
                if(ns>nw&&!vis.count(nset))vis[nset]=ns,q.push({nset,{ns,nw}});
            }
    }
    int ans=0;
    for(auto [a,b]:vis)ans=max(ans,b);
    return ans;
}