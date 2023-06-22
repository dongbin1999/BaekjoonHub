#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<vector<pii>> tree;

int ans=0;
vector<int> f(int node,int parent){
    vector<int> ret={0,0};
    int pdir=-1;
    for(auto [nx,dir]:tree[node])
        if(nx!=parent){
            vector<int> child=f(nx,node);
            ret[0]+=child[0],ret[1]+=child[1];
        }
        else pdir=dir;

    int x=min(ret[0],ret[1]);
    ans+=x,ret[0]-=x,ret[1]-=x;
    if(pdir==-1) ans+=ret[0]+ret[1];
    else if(ret[pdir])ans+=ret[pdir],ret[pdir]=0,ret[!pdir]=1;
    else if(!ret[!pdir])ret[!pdir]++;
    return ret;
}

void solve(){
    int n;scanf("%d",&n);
    vector<pii> t;
    tree.assign(n,t);
    ans=0;
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back({y,1});
        tree[y].push_back({x,0});
    }
    int root=-1;
    for(int i=0;i<n;i++)if(tree[i].size()==1)root=i;
    vector<int> x=f(root,root);
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case %d: ",i);
        solve();
    }
    return 0;
}