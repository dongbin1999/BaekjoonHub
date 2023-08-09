#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;

int dist[331][331];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alpmax=0,copmax=0;
    for(auto v:problems)alpmax=max(alpmax,v[0]),copmax=max(copmax,v[1]);
    vector<vector<int>> p;
    for(auto v:problems) if(v[4]<v[2]+v[3])p.push_back(v);
    problems=p;
    memset(dist,0x3f,sizeof(dist));
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    pq.push({0,min(alpmax,alp),min(copmax,cop)});
    while(!pq.empty()){
        auto [cost,a,c]=pq.top();pq.pop();
        if(a>=alpmax&&c>=copmax)return cost;
        if(dist[a][c]<1e9)continue;
        dist[a][c]=cost;
        pq.push({cost+1,min(alpmax,a+1),c});
        pq.push({cost+1,a,min(copmax,c+1)});
        for(vector<int> v:problems)
            if(v[0]<=a&&v[1]<=c)
                pq.push({cost+v[4],min(a+v[2],alpmax),min(copmax,c+v[3])});
    }
}