#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;

vector<arr> v[1001];

int main(){
    int n,t,m,s,e;scanf("%d%d%d%d%d",&n,&t,&m,&s,&e);
    vector<int> d(n,1e9);d[s]=0;
    for(int i=1;i<=t;i++){
        for(int j=0;j<m;j++){
            int x,y,c;scanf("%d%d%d",&x,&y,&c);
            v[i].push_back({x,y,c});
        }
    }
    for(int i=1;i<=t;i++){
        vector<int> nd=d;
        for(auto [x,y,c]:v[i]){
            nd[y]=min(nd[y],d[x]+c);
            nd[x]=min(nd[x],d[y]+c);
        }
        d=nd;
    }
    printf("%d",d[e]==1e9?-1:d[e]);
}