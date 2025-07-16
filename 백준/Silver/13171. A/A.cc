#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll mod=1e9+7;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    long long x,y;cin>>x>>y;
    ll xx=x,yy=y;
    cout<<(long long)power(xx,yy);
}