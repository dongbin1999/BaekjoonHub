#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> tree[100000];
ll c[2][100000];
void go(int node=0,int pa=0){
    ll w=0,mn=0;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        go(nx,node);
        w+=c[0][nx],mn+=min(c[0][nx],c[1][nx]);
    }
    c[1][node]+=w,c[0][node]+=mn;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    for(int i=0;i<n;i++)scanf("%lld%lld",&c[0][i],&c[1][i]);
    go();
    printf("%lld",min(c[0][0],c[1][0]));
    return 0;
}