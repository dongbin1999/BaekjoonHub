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
    ll x,y;scanf("%lld%lld",&x,&y);
    if(__builtin_popcount(y)>1){printf("-1");return;}
    string s;
    while(x){
        s+=x&1?"GK":"K";
        x>>=1;
    }
    for(auto c:s)if(c=='K')y>>=1;
    while(y>1)s+='K',y>>=1;
    cout<<s;
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}