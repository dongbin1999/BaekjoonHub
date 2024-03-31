#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> dag(n+1),rdag(n+1);
    vector<int> in(n+1),rin(n+1);
    vector<set<int>> v(n+1),rv(n+1);
    for(auto i:results){
        dag[i[0]].push_back(i[1]),in[i[1]]++;
        rdag[i[1]].push_back(i[0]),rin[i[0]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)if(!in[i])q.push(i);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:dag[cur]){
            for(auto i:v[cur])v[nx].insert(i);
            v[nx].insert(cur);
            if(--in[nx]==0)q.push(nx);
        }
    }
    for(int i=1;i<=n;i++)if(!rin[i])q.push(i);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:rdag[cur]){
            for(auto i:rv[cur])rv[nx].insert(i);
            rv[nx].insert(cur);
            if(--rin[nx]==0)q.push(nx);
        }
    }
    
    int answer=0;
    for(int i=1;i<=n;i++)if(v[i].size()+rv[i].size()==n-1)answer++;
    return answer;
}