#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,3> tup;
const ll mod=1e9+7;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

set<int> tree[200001];

void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)tree[i].clear();
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].insert(y),tree[y].insert(x);
    }
    vector<pii> v;
    for(int i=1;i<=n;i++)v.push_back({tree[i].size(),i});
    sort(v.begin(),v.end(),greater<pii>());

    int ans=0;
    for(int i=0;i<min(n,5);i++)for(int j=i+1;j<n;j++){
            int tmp=1+v[i].first-1+v[j].first-1;
            if(tree[v[i].second].count(v[j].second))tmp--;
            ans=max(ans,tmp);
        }
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}