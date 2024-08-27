#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> tree[100001];

ll sum,mx;
void dfs(ll node,ll pa,ll d=0){
    mx=max(mx,d);
    for(auto [nx,cost]:tree[node])
        if(nx!=pa)dfs(nx,node,d+cost),sum+=cost;
}

int main(){
    int n,s;scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++){
        ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
        tree[x].push_back({y,z}),tree[y].push_back({x,z});
    }
    dfs(s,-1);
    printf("%lld",sum*2-mx);
}