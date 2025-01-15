#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,2> pll;
int c[100001];
vector<int> tree[100001];
pll rb[100001],all;
ll add[100001];

pll go(int node=1,int pa=-1){
    vector<pll> v;
    pll sum={0,0};
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        v.push_back(go(nx,node));
        sum[0]+=v.back()[0],sum[1]+=v.back()[1];
    }
    for(auto [b,r]:v)
        add[node]+=(sum[0]-b)*r+(sum[1]-r)*b;
    sum[c[node]]++;
    return rb[node]=sum;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),all[c[i]]++;
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    int q;scanf("%d",&q);
    while(q--){
        int x;scanf("%d",&x);
        pll sub=rb[x],out=all;
        out[0]-=sub[0],out[1]-=sub[1];
        sub[c[x]]--;
        printf("%lld\n",sub[0]*out[1]+sub[1]*out[0]+add[x]/2);
    }
}