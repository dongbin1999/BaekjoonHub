#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree[250001];
ll u[250001],pa[250001],ans;

ll find(ll x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(ll a,ll b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    ans+=u[b]*u[a],u[a]+=u[b],u[b]=a;
    return 1;
}
void go(int node=1,int p=1){
    pa[node]=p;
    for(auto nx:tree[node])
        if(nx!=p)go(nx,node);
}
int main(){
    int n;scanf("%d",&n);
    memset(u,-1,sizeof(u));
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go();
    int q;scanf("%d",&q);
    while(q--){
        int m;scanf("%d",&m);
        unordered_set<int> se;
        while(m--){
            int x;scanf("%d",&x);
            se.insert(x);
        }
        for(auto i:se)if(se.count(pa[i]))merge(i,pa[i]);
        printf("%lld\n",ans);
        for(auto i:se)u[i]=-1;ans=0;
    }
    return 0;
}