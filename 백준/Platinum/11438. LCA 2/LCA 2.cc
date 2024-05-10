#include <bits/stdc++.h>
using namespace std;

const int sz=17;
vector<int> tree[1<<sz];
int depth[1<<sz],sparse[1<<sz][sz];

void go(int node=1,int d=0,int parent=1){
    sparse[node][0]=parent,depth[node]=d;
    for(int i=1;i<sz;i++)sparse[node][i]=sparse[sparse[node][i-1]][i-1];
    for(int to:tree[node])if(parent!=to)go(to,d+1,node);
}
int LCA(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    for(int i=sz-1;i>=0;i--)if(depth[sparse[b][i]]>=depth[a])b=sparse[b][i];
    if(a==b)return a;
    for(int i=sz-1;i>=0;i--)
        if(sparse[a][i]!=sparse[b][i])
            a=sparse[a][i],b=sparse[b][i];
    return sparse[a][0];
}

int main(){
    int n,m;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d %d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    scanf("%d",&m);
    while(m--){
        int a,b;scanf("%d %d",&a,&b);
        printf("%d\n",LCA(a,b));
    }
}