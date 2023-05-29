#include <bits/stdc++.h>
using namespace std;

vector<int> tree[101];
int ans,h;
int go(int node,int pa){
    int ret=0;
    for(auto nx:tree[node])if(nx!=pa)
        ret=max(ret,go(nx,node));
    if(ret+1>=h&&pa)ret--,ans++;
    return ret+1;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d %d",&x,&y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    scanf("%d",&h);
    go(0,0);
    printf("%d",ans);
    return 0;
}