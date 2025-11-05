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

unordered_map<ll,ll> ma;
ll p,q,x,y;
ll f(ll i){
    if(i<=0)return 1;
    if(ma.count(i))return ma[i];
    return ma[i]=f(i/p-x)+f(i/q-y);
}

void solve(){
    ll n;cin>>n>>p>>q>>x>>y;
    printf("%lld",f(n));
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}