#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod[2]={998244353,1000000007},base=100001;

vector<int> tree[100001];
map<ll,ll> ma;
ll ans;
pll go(int node=1,ll pa=-1){
    ll p1=1,p2=1;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        auto [x,y]=go(nx,node);
        p1=(p1+x*base)%mod[0],p2=(p2+y*base)%mod[1];
    }
    ans+=ma[p1*mod[1]+p2]++;
    return {p1,p2};
}

int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    printf("%lld",ans);
}