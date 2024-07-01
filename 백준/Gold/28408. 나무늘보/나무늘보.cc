#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

int pre[500002],post[500002],postidx[500002];
int n,preidx=1;
vector<int> tree[500002];

void go(int pa=-1,int l=1,int r=n){
    if(l>r||preidx>n)return;
    int node=pre[preidx],mid=postidx[pre[++preidx]];
    if(mid<=r)go(node,l,mid),go(node,mid+1,r-1);
    if(pa!=-1)tree[pa].push_back(node);
}

vector<int> pre2(1),post2(1);
void preorder(int node){
    pre2.push_back(node);
    for(auto nx:tree[node])preorder(nx);
}

void postorder(int node){
    for(auto nx:tree[node])postorder(nx);
    post2.push_back(node);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&pre[i]);
    for(int i=1;i<=n;i++)scanf("%d",&post[i]),postidx[post[i]]=i;
    go();
    int root=pre[1];
    preorder(root),postorder(root);
    for(int i=1;i<=n;i++)if(pre[i]!=pre2[i]||post[i]!=post2[i])return !printf("0");
    int ans=1;
    for(int i=1;i<=n;i++)if(tree[i].size()==1)ans=ans*2%mod;
    printf("%d",ans);
}