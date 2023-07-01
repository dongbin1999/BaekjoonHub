#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

ll u[100001];
map<ll,ll> ma[100001];
ll ans[50001];
ll v[100001];

int find(int a){
    if(u[a]<0)return a;
    return u[a]=find(u[a]);
}

bool merge(int a,int b,ll k){
    a=find(a),b=find(b);
    if(a==b)return false;
    if(ma[a].size()<ma[b].size())swap(a,b);
    for(auto [company,num]:ma[b]){
        ans[company]+=ma[a][company]*num*k;
        ma[a][company]+=num;
    }
    u[a]+=u[b];
    u[b]=a;
    return true;
}

int main(){
    int n,k,m;scanf("%d%d%d",&n,&k,&m);
    vector<vector<ll>> edges;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        ma[i][v[i]]++;
    }
    while(m--){
        int x,y; ll w;scanf("%d%d%lld",&x,&y,&w);
        edges.push_back({w,x,y});
    }
    sort(edges.begin(),edges.end(),greater<vector<ll>>());
    memset(u,-1,sizeof(u));
    for(int i=0;i<edges.size();i++){
        ll w=edges[i][0],x=edges[i][1],y=edges[i][2];
        merge(x,y,w);
    }
    for(int i=1;i<=k;i++)printf("%lld\n",ans[i]);

    return 0;
}