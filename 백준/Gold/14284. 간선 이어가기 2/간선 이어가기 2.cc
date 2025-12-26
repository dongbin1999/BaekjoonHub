//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,3> arr;
const ll mod=1e9+7;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
char a[200000],b[200000];
void solve(){

}
vector<pii> g[5001];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    while(m--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        g[x].push_back({y,z}),g[y].push_back({x,z});
    }
    int s,t;scanf("%d%d",&s,&t);
    pq.push({0,s});
    vector<int> ds(n+1,1e9);
    while(!pq.empty()){
        auto [d,c]=pq.top();pq.pop();
        if(ds[c]<=d)continue;ds[c]=d;
        for(auto [nx,co]:g[c])pq.push({d+co,nx});
    }
    printf("%d",ds[t]);
    return 0;
}