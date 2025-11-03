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

char s[1002][1002];

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=1;i<n;i++)for(int j=1;j<m;j++){
        vector<int> v(26);
        v[s[i-1][j-1]-'A']++;v[s[i][j-1]-'A']++;v[s[i-1][j]-'A']++;v[s[i][j]-'A']++;
        for(auto k:v)if(k==3){printf("BaboBabo");return;}
    }
    printf("dd");
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}