#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,3> tup;
const ll mod=998244353;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}


int main(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    if(a+b==c)printf("correct!");
    else printf("wrong!");
    return 0;
}