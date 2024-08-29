#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> tree[1000001];
pii sub[1000001];

pii go(int node=1,int pa=-1){
    int e=0,o=0;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        auto [co,ce]=go(nx,node);
        e+=co,o+=ce;
    }
    if(tree[node].size()<=1)o++;
    return sub[node]={o,e};
}

int mx;
void dfs(int node=1,int pa=-1,pii oe={0,0}){
    auto [o,e]=sub[node];
    auto [po,pe]=oe;
    if(tree[node].size()<=1)o--;
    //printf("%d :%d %d %d %d\n",node,o,e,po,pe);
    mx=max(mx,o+po);
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        auto [no,ne]=sub[nx];
        dfs(nx,node,{pe+e-no,po+o-ne+(tree[node].size()==1)});
    }
}

int main(){
    int n;scanf("%d",&n);
    if(n==1)return !printf("1");
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go(),dfs();
    printf("%d",mx);
}