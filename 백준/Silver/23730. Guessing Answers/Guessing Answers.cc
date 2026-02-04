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
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> a(n+1),b(n+2),c(n+2);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        b[x]=1;
    }
    for(int i=1;i<=n;i++)if(b[i])c[i]=a[i];
    for(int i=1;i<=n;i++){
        if(b[i])continue;
        set<int> se={1,2,3,4,5};
        if(se.count(c[i-1]))se.erase(c[i-1]);
        if(se.count(c[i+1]))se.erase(c[i+1]);
        if(se.count(a[i]))se.erase(a[i]);
        c[i]=*se.begin();
    }
    for(int i=1;i<=n;i++)printf("%d ",c[i]);
    return 0;
}