#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<int> tree[100001];
pll p[100001];
ll d[100001];
pll dfs(int node=1,int pa=-1,int dep=0){
    ll odd=0,even=1;
    d[node]=dep;
    for(auto nx:tree[node]){
        if(pa==nx)continue;
        auto [co,ce]=dfs(nx,node,dep+1);
        odd+=co,even+=ce;
    }
    p[node]={odd,even};
    return {even,odd};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d %d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    dfs();
    while(m--){
        int u,v,c;scanf("%d%d%d",&u,&v,&c);
        if(d[u]<d[v])swap(u,v);
        auto [uo,ue]=p[u];auto [vo,ve]=p[1];
        if(d[u]%2)vo-=ue,ve-=uo;else vo-=uo,ve-=ue;
        if(d[v]%2)swap(vo,ve);
        if(c)printf("%lld\n",vo*uo+ve*ue);
        else printf("%lld\n",vo*ue+ve*uo);
    }
    return 0;
}