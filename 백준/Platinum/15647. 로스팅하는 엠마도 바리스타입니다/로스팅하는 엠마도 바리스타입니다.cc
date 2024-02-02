#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;

vector<pil> tree[300001];
vector<pil> sub[300001];
pil subsum[300001];
ll ans[300001];

pil go(int node=1,int pa=-1){
    int cnt=0;ll sum=0;
    for(auto [nx,d]:tree[node]){
        if(nx==pa)continue;
        sub[node].push_back(go(nx,node));
        auto &[x,y]=sub[node].back();
        x++,y+=d*x;
        cnt+=x,sum+=y;
    }
    return subsum[node]={cnt,sum};
}

void go2(int node,int pa,int cnt,ll sum){
    auto [curc,curs]=subsum[node];
    ans[node]=sum+curs;
    int idx=0;
    for(auto [nx,d]:tree[node]){
        if(nx==pa)continue;
        auto [nxc,nxs]=sub[node][idx++];
        nxc=curc-nxc+cnt,nxs=curs-nxs+sum;
        go2(nx,node,nxc+1,nxs+(nxc+1)*d);
    }
}

int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;ll d;scanf("%d%d%lld",&u,&v,&d);
        tree[u].push_back({v,d});
        tree[v].push_back({u,d});
    }
    go();
    go2(1,-1,0,0);
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
}