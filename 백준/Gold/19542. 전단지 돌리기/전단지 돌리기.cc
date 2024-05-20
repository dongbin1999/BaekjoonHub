#include<bits/stdc++.h>
using namespace std;
vector<int> tree[100001];

vector<int> a;
int d;
int go(int node,int pa=-1){
    int ret=0;
    for(auto nx:tree[node])
        if(nx!=pa)ret=max(ret,go(nx,node));
    if(ret<d)a[node-1]=0;
    return ret+1;
}

int main(){
    int n,s;scanf("%d%d%d",&n,&s,&d);
    a.assign(n,1);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go(s);
    printf("%d",max(0,accumulate(a.begin(),a.end(),-1))<<1);
}