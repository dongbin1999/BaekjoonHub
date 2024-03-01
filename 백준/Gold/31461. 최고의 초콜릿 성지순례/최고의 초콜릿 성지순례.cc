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

ll s[3][200002];

void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&s[1][i]);
    for(int i=1;i<=n;i++)scanf("%lld",&s[2][i]);
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>c)swap(a,c),swap(b,d);

    ll l=s[1][a]+s[2][a],r=s[1][c]+s[2][c];
    ll x=0;
    for(int i=a-1;i>=1;i--){
        x+=s[1][i+1]+s[2][i+1];
        l=max(l,x+max({0ll,s[1][i],s[2][i],s[1][i]+s[2][i]}));
    }
    x=0;
    for(int i=c+1;i<=n;i++){
        x+=s[1][i-1]+s[2][i-1];
        r=max(r,x+max({0ll,s[1][i],s[2][i],s[1][i]+s[2][i]}));
    }
    if(a==c){
        printf("%lld\n",max(l,r));
    }
    else{
        l=max(l,s[b][a]),r=max(r,s[d][c]);
        ll ans=l+r;
        for(int i=a+1;i<c;i++){
            ans+=max({s[1][i],s[2][i],s[1][i]+s[2][i]});
        }
        printf("%lld\n",ans);
    }
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}