#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tup;
ll power(ll a,ll b,ll mod){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}

tup EEA(ll a,ll b,ll x1=1,ll x2=0,ll y1=0,ll y2=1){
    if(b==0)return {a,x1,y1};
    ll q=a/b,r=a%b,x=x1-q*x2,y=y1-q*y2;
    return EEA(b,r,x2,x,y2,y);
}

int main(){
    ll n;scanf("%lld",&n);
    ll A[3]={23,307,141623},v[3];
    for(int i=0;i<3;i++){
        ll a=(power(9,(n+1)/2,A[i])+A[i]-1)%A[i],b=(power(9,n/2,A[i])+A[i]-1)%A[i];
        if(n%2)v[i]=(a-b*3+A[i]*3)%A[i]*power(8,A[i]-2,A[i])%A[i]*4%A[i];
        else v[i]=(power(9,n/2,A[i])+3)%A[i];
    }
    ll ans=0,mod=A[0]*A[1]*A[2];
    for(int i=0;i<3;i++){
        auto [gcd,x,y]=EEA(A[(i+1)%3]*A[(i+2)%3]%A[i],A[i]);
        ll s=x>0?x:x+A[i];
        ans+=s*mod/A[i]*v[i];
    }
    ans%=mod;
    printf("%lld",ans);
    return 0;
}