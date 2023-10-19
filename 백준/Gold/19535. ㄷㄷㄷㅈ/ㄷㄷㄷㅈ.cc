#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tree[300001];
ll d,g;
void go(int node,int pa=-1){
    ll x=tree[node].size();
    g+=x*(x-1)*(x-2)/6;
    for(auto nx:tree[node])
        if(nx!=pa){
            ll y=tree[nx].size();
            d+=(x-1)*(y-1);
            go(nx,node);
        }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v),tree[v].push_back(u);
    }
    go(1);
    if(d>g*3)printf("D");
    else if(d<g*3)printf("G");
    else printf("DUDUDUNGA");
    return 0;
}