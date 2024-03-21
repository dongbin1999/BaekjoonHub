#include<bits/stdc++.h>
using namespace std;

vector<int> tree[100001],c(100001);
bool go(int node=1,int pa=-1){
    int color=0;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        color|=!go(nx,node);
    }
    return c[node]=color;
}

int solution(int n, vector<vector<int>> lighthouse) {
    for(auto v:lighthouse){
        tree[v[0]].push_back(v[1]);
        tree[v[1]].push_back(v[0]);
    }
    go();
    return accumulate(c.begin(),c.end(),0);
}