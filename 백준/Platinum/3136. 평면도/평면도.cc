#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
set<pair<pii,pii>> edge;
set<pii> vertex;

int main(){
    int n;scanf("%d",&n);
    int x=0,y=0;
    vertex.insert({x,y});
    while(n--){
        int d;scanf("%1d",&d);
        auto [dx,dy]=go[d];
        int nx=x+dx,ny=y+dy;
        pii s={x,y},e={nx,ny};
        if(s>e)swap(s,e);
        vertex.insert({nx,ny}),edge.insert({s,e});
        x+=dx,y+=dy,nx=x+dx,ny=y+dy;
        s={x,y},e={nx,ny};
        if(s>e)swap(s,e);
        vertex.insert({nx,ny}),edge.insert({s,e});
        x+=dx,y+=dy;
    }
    printf("%d",edge.size()-vertex.size()+1);
}