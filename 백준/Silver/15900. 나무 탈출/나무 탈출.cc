#include<bits/stdc++.h>
using namespace std;

vector<int> tree[500001];
int d[500001];
void go(int node=1,int pa=-1,int dep=0){
    d[node]=dep;
    for(auto nx:tree[node])
        if(nx!=pa)go(nx,node,dep+1);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    long long ans=0;
    for(int i=1;i<=n;i++)if(tree[i].size()==1&&i!=1)ans+=d[i];
    if(ans%2)printf("Yes");else printf("No");
}