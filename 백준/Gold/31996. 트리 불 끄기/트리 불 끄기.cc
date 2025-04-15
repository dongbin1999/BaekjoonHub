#include<bits/stdc++.h>
using namespace std;
int a[100001];
vector<int> tree[100001];
deque<int> ans;
void go(int node,int pa=0){
    a[pa]^=1,ans.push_back(node);
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        if(tree[nx].size()==1&&!a[nx])continue;
        go(nx,node),ans.push_back(node),a[nx]^=1;
        if(a[nx])ans.push_back(nx),ans.push_back(node),a[nx]^=1,a[node]^=1;
    }
}

int main(){
    int n,s;scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go(s);
    if(a[s])ans.push_back(tree[s][0]),a[s]^=1;
    ans.pop_front();
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}