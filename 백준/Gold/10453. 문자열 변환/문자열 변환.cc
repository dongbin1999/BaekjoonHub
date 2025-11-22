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
    scanf("%s %s",a,b);
    vector<ll> x,y;
    for(int i=0,n=strlen(a);i<n;i++)if(a[i]=='a')x.push_back(i);
    for(int i=0,n=strlen(b);i<n;i++)if(b[i]=='a')y.push_back(i);
    ll ans=0;
    for(int i=0;i<x.size();i++)ans+=abs(x[i]-y[i]);
    printf("%lld\n",ans);
}

int main(){
    int tc=1;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}