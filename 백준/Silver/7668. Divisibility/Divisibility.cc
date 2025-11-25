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

}

int main(){
    // int tc=1;scanf("%d",&tc);
    // while(tc--)solve();
    map<int,int>ma;
    for(int i='1';i<='9';i++)ma[i]=ma.size()+1;
    for(int i='A';i<='Z';i++)ma[i]=ma.size()+1;
    for(int i='a';i<='z';i++)ma[i]=ma.size()+1;
    while(1){
        string s;cin>>s;
        if(s=="end")break;
        int x=0;
        for(auto c:s)x+=ma[c];
        printf(x%61?"no\n":"yes\n");
    }
    return 0;
}