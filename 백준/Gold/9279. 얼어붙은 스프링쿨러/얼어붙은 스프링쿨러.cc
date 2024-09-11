#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> tree[1001];
int go(int node,int pa=-1){
    int ret=1e9,child=0;
    for(auto [nx,w]:tree[node]){
        if(nx==pa)ret=w;
        else child+=go(nx,node);
    }
    return min(ret,child?child:INT_MAX);
}

int main(){
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF){
        for(int i=1;i<=1000;i++)tree[i].clear();
        for(int i=1;i<n;i++){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            tree[x].push_back({y,z}),tree[y].push_back({x,z});
        }
        printf("%d\n",go(c));
    }
}