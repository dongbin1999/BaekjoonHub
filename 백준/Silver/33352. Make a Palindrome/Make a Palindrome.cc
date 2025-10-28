#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tup;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

bool solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<int,int> ma;
    if(n%2){
        string a,b;
        for(int i=0;i<n;i++)(i%2?a:b)+=s[i];
        int cnt=0,sz=a.size();
        for(auto c:a)ma[c]++;
        for(auto [x,y]:ma)cnt+=y/2;
        if(cnt<sz/2)return 0;
        ma.clear(),cnt=0,sz=b.size();
        for(auto c:b)ma[c]++;
        for(auto [x,y]:ma)cnt+=y/2;
        if(cnt<sz/2)return 0;
        return 1;
    }
    else{
        for(int i=0;i<n;i+=2)ma[s[i]]++;
        for(int i=1;i<n;i+=2)ma[s[i]]--;
        for(auto [x,y]:ma)if(y)return 0;
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;cin>>tc;
    while(tc--)cout<<(solve()?"YES\n":"NO\n");
    return 0;
}