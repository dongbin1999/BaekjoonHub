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
vector<int> tree[100001];

void solve(){
    int n;scanf("%d",&n);
    vector<pii> e;
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
        e.push_back({x,y});
    }
    int k=3;printf("%d\n",k);
    for(int i=1;i<=n;i++)if(tree[i].size()>=3){
        vector<int> a;
        for(int nx=0;nx<k;nx++)a.push_back(tree[i][nx]);
        for(int x=0;x<k;x++)for(int y=x+1;y<k;y++)printf("%d %d\n",a[x],a[y]);
        return;
    }
    for(auto [x,y]:e)if(tree[x].size()>1&&tree[y].size()>1){
        vector<int> a;
        for(auto nx:tree[x])if(nx!=y){a.push_back(nx);break;}
        for(auto nx:tree[y])if(nx!=x){a.push_back(nx);break;}
        printf("%d %d\n",a[0],a[1]);
        printf("%d %d\n",a[0],y);
        printf("%d %d\n",a[1],x);
        return;
    }
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}