#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> go={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int solution(vector<int> arrows) {
    vector<int> tmp;
    for(auto i:arrows)tmp.push_back(i),tmp.push_back(i);
    arrows=tmp;
    int ans=0;
    set<array<int,4>> line;
    set<pii> point;
    int x=0,y=0;
    point.insert({x,y});
    for(auto p:arrows){
        auto[dx,dy]=go[p];
        int nx=x+dx,ny=y+dy;
        if(point.count({nx,ny})&&!line.count({x,y,nx,ny}))ans++;
        point.insert({nx,ny}),line.insert({x,y,nx,ny}),line.insert({nx,ny,x,y});
        x=nx,y=ny;
    }
    return ans;
}