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

void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n),ans(n);
    for(auto &x:v)scanf("%d",&x);
    int c=0;
    while(c<n){
        int x=-1;
        for(int i=0;i<n;i++)if(!v[i])x=i;
        if(x==-1){printf("IMPOSSIBLE\n");return;}
        ans[x]=++c;
        for(int i=x+1;i<n;i++)v[i]--;
        v[x]=1e9;
    }
    for(auto i:ans)printf("%d ",i);
    printf("\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}