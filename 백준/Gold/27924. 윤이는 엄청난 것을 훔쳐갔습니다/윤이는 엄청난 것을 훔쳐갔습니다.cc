#include <bits/stdc++.h>
using namespace std;
vector<int> tree[200001];
int depth[3][200001];
void go(int node,int d,int pa,int root){
    depth[root][node]=d;
    for(auto nx:tree[node])
        if(nx!=pa)go(nx,d+1,node,root);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    go(a,0,a,0),go(b,0,b,1),go(c,0,c,2);
    for(int i=1;i<=n;i++)if(tree[i].size()==1&&min(depth[1][i],depth[2][i])>depth[0][i])
        return !printf("YES");
    printf("NO");
    return 0;
}
