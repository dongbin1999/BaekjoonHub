#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> tree[100001];
int go(int node=1,int pa=-1){
    int ret=0,x=2e9;
    for(auto [nx,cost]:tree[node]){
        if(nx==pa)x=cost;
        else ret+=go(nx,node);
    }
    if(tree[node].size()==1&&node!=1)return x;
    else return min(ret,x);
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    printf("%d",go());
}