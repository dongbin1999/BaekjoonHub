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
    string s;cin>>s;
    int x=0;
    sort(s.begin(),s.end());
    do{
        int y=1;
        for(int i=1;i<s.size();i++)y&=s[i]!=s[i-1];
        x+=y;
    }while(next_permutation(s.begin(),s.end()));
    cout<<x;
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}