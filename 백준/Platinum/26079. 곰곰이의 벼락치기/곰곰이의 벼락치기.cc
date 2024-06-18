#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int in[200001];
vector<int> tree[200001];
ll fac[200001]={1};

pll go(int node){
    ll cnt=0,ret=1;
    vector<ll> child;
    for(auto nx:tree[node]){
        auto [x,y]=go(nx);
        ret=ret*x%mod,child.push_back(y),cnt+=y;
    }
    ret=ret*fac[cnt]%mod;
    for(auto i:child)ret=ret*power(fac[i],mod-2)%mod;
    return{ret,cnt+1};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),in[b]=1;
    }
    for(int i=1;i<=n;i++)if(!in[i])tree[0].push_back(i);
    printf("%lld",go(0).first);
}