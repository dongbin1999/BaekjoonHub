#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=10000000ll;
char s[1003];
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
void solve(){
    ll a,b,x;scanf("%lld%lld%lld",&a,&b,&x);
    a%=mod;
    scanf("%s",s);int n=strlen(s);
    ll y=power(10,x);
    ll c=0;
    for(int i=max(0,n-7);i<n;i++)
        c=c*10+s[i]-'0';
    if(c>=7||n>7)c+=1e7;
    ll d=power(b%mod,c);
    if(d>=7||b>=mod||(b==2&&c>=3)||(b>=3&&c>=2))d+=1e7;
    ll ans=power(a,d);
    printf("%lld\n",(ans/y)%10);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}