#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%MOD;a=a*a%MOD;b/=2;}return ret;}
const int sz = 1<<17;

int main()
{
    int n;
    scanf("%d",&n);
    map<ll,ll> ma;
    vector<ll> v;
    for(int i=1;i<=n;i++)
    {
        ll a;
        scanf("%lld",&a);
        ma[a]++;
        v.push_back(a);
    }
    UNIQUE(v)
    ll x;scanf("%lld",&x);
    ll ans=0, l=0,r=v.size()-1;
    while(l<=r)
    {
        if(v[l]+v[r]==x)
        {
            if(v[l]==v[r])
            {
                ll temp=ma[v[l]];
                ans+=(temp*temp-temp)/2ll;
            }
            else
                ans+=ma[v[l]]*ma[v[r]];
            l++;
        }
        else if(v[l]+v[r]>x)
            r--;
        else
            l++;
    }
    printf("%lld",ans);
    return 0;
}