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
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    sort(a.begin(),a.end());
    vector<vector<int>> b(m,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)b[j][i]=a[i][j];
    sort(b.begin(),b.end());
    vector<int> x,y;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)x.push_back(b[j][i]);
    y=x;sort(y.begin(),y.end());
    printf("%d",x==y);
    return 0;
}