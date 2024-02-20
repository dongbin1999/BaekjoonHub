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
    int n,k;
    scanf("%d %d",&n,&k);
    int m[31]={1};
    for(int i=1;i<=30;i++)
        m[i]=m[i-1]*2;
    while(k>1 && n)
    {
        int temp=0;
        for(int i=0;i<=30;i++)
            if(m[i]<=n)
                temp=i;
        n-=m[temp], k--;
    }
    if(!n)
        return !printf("0");
    int temp = 1e9;
    for(int i=0;i<=30;i++)
        if(m[i]>=n)
            temp=min(temp,i);
    printf("%d",m[temp]-n);
    return 0;
}