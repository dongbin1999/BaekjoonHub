#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int a[100001],b[100001],ans;
vector<int> tree[100001];
int dfs(int node,int pa=-1){
    vector<int> v;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        v.push_back(dfs(nx,node));
    }
    if(v.empty())return max(0,b[node]-a[node]);
    sort(v.begin(),v.end());
    int soil=max(0,a[node]-b[node]),ret=max(0,b[node]-a[node]);
    ret+=max(0,accumulate(v.begin(),v.end(),0)-soil);
    return ret;
}

int main(){
    int n,p;scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    printf("%d",dfs(p));
    return 0;
}