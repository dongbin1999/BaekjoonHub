#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> tree[200001];
int x,y,root;
void go(int node,int pa=-1,int sum=0,bool pillar=1){
    if(pillar)x=max(x,sum);
    y=max(y,sum);
    for(auto [nx,cost]:tree[node]){
        if(nx==pa)continue;
        go(nx,node,sum+cost,pillar&((int)tree[node].size()-(root!=node)==1));
    }
}

int main(){
    int n,r;scanf("%d%d",&n,&r);
    for(int i=1;i<n;i++){
        int a,b,d;scanf("%d%d%d",&a,&b,&d);
        tree[a].push_back({b,d}),tree[b].push_back({a,d});
    }
    root=r,go(r);
    printf("%d %d",x,y-x);
    return 0;
}