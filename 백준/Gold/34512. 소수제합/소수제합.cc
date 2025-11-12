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

bool prime(int n){
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
vector<int> a,v;
bool ok=0;
void go(int n){
    if(a.size()==n){
        int sum=0;
        for(auto x:a)sum+=x*x;
        set<int> se;
        se.insert(a.begin(),a.end());
        ok=se.size()>1;
        for(auto x:a)ok&=sum%x==0;
        if(ok){for(auto x:a)printf("%d ",x);exit(0);}
        return;
    }
    for(auto x:v)a.push_back(x),go(n),a.pop_back();
}

void solve(){
    int n;scanf("%d",&n);
    if(n>6||n==5){
        int three=1;n-=3;
        int two=n/2;
        if(n%2)n-=3,three++,two=n/2;
        while(two--)printf("3 3 ");
        while(three--)printf("2 2 2 ");
    }
    else{
        for(int i=2;i<=150;i++)if(prime(i))v.push_back(i);
        go(n);
        printf("-1");
    }
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}