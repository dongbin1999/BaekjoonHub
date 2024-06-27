#include <bits/stdc++.h>
using namespace std;
const int sz=17;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tup;
typedef pair<ll,ll> pll;
//(1<<sz)>=n이 되게 관리.
vector<tup> tree[1<<sz];
int depth[1<<sz];//depth[i] : i번 노드의 깊이(루트노드에서부터의 거리)
int sparse[1<<sz][sz];//sparse[i][j] : i번째 노드의 2^j번째 부모. 1번(루트)노드의 부모도 1이라고 가정.
pll sparse_sum[1<<sz][sz];

map<pii,pll> zr;

void go(int node,int d,int parent){
    sparse[node][0]=parent;
    sparse_sum[node][0]=zr[{node,parent}];
    depth[node]=d;
    for(int i=1;i<sz;i++){
        sparse[node][i]=sparse[sparse[node][i-1]][i-1];
        auto [x,y]=sparse_sum[sparse[node][i-1]][i-1];
        auto [xx,yy]=sparse_sum[node][i-1];
        ll nx;
        if((ll)4e18/max(1ll,xx)<x)nx=2e18;
        else nx=x*xx;
        sparse_sum[node][i]={nx,y+yy};
    }
    for(auto [to,r,z]:tree[node])
        if(parent!=to)
            go(to,d+1,node);
}

int LCA(int a,int b){
    if(depth[a]>depth[b])
        swap(a,b);//b가 더 깊은 점.
    for(int i=sz-1;i>=0;i--)//b를 a 높이까지 올려줌.
        if(depth[sparse[b][i]]>=depth[a])
            b=sparse[b][i];
    if(a==b)return a;//a,b가 같은 점이면 그 점이 LCA.
    for(int i=sz-1;i>=0;i--)
        if(sparse[a][i]!=sparse[b][i])
            a=sparse[a][i],b=sparse[b][i];
    return sparse[a][0];//a,b의 한단계 위가 LCA.
}

tup LCA2(int a,int lca){
    ll x=1,y=0;
    for(int i=sz-1;i>=0;i--)
        if(depth[sparse[a][i]]>=depth[lca]&&sparse_sum[a][i].first==1)
            y+=sparse_sum[a][i].second,a=sparse[a][i];
    return {a,x,y};
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        ll x,y,r,z;scanf("%lld%lld%lld%lld",&x,&y,&r,&z);
        tree[x].push_back({y,z,r});
        tree[y].push_back({x,z,r});
        zr[{x,y}]=zr[{y,x}]={z,r};
    }
    go(1,0,1);
    int q;scanf("%d",&q);
    while(q--){
        int a,b;ll e;scanf("%d%d%lld",&a,&b,&e);
        int lca=LCA(a,b);
        vector<pll> v,rev;
        while(a!=lca){
            auto [nx,x,y]=LCA2(a,lca);
            v.push_back({x,y});
            a=nx;
            if(a!=lca)v.push_back(sparse_sum[a][0]),a=sparse[a][0];
            if(rev.size()+v.size()>130)break;
        }
        while(b!=lca){
            auto [nx,x,y]=LCA2(b,lca);
            rev.push_back({x,y});
            b=nx;
            if(b!=lca)rev.push_back(sparse_sum[b][0]),b=sparse[b][0];
            if(rev.size()+v.size()>130)break;
        }
        if(rev.size()+v.size()>130){printf("0\n");continue;}
        while(!rev.empty())v.push_back(rev.back()),rev.pop_back();
        for(auto [x,y]:v){
            e=max(0ll,(e-y))/x;if(!e)break;
        }
        printf("%lld\n",e);
    }
    return 0;
}