#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
int a[200001],mex[200001];
unordered_multiset<int> se[200001];
int go(int node,int pa=-1){
    int large=node;
    vector<int> child;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        child.push_back(go(nx,node));
        if(se[large].size()<se[child.back()].size())large=child.back();
        mex[node]=max(mex[node],mex[nx]);
    }
    for(auto c:child){
        if(c==large)continue;
        for(auto i:se[c])se[large].insert(i);
        se[c].clear();
    }
    if(large!=node)se[large].insert(*se[node].begin()),se[node].clear();
//    printf("%d: ",node);
//    for(auto i:se[large])printf("%d ",i);
//    printf("\n");
    while(se[large].count(mex[node]))mex[node]++;
    return large;
}

int main(){
    int n;scanf("%d",&n);
    int root;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(x==-1)root=i;
        else tree[x].push_back(i),tree[i].push_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),se[i].insert(a[i]);
    go(root);
    for(int i=1;i<=n;i++)printf("%d\n",mex[i]);
}