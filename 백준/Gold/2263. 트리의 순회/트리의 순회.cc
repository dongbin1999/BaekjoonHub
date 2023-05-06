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

int in[100001],post[100001];
vector<int> pre;

void go(int inl, int inr, int postl, int postr)
{
    if(inl>inr||postl>postr) return;
    pre.push_back(post[postr]);
    int temp=in[post[postr]];
    int mid=postl+temp-inl-1;
    go(inl,temp-1,postl,mid);
    go(temp+1,inr,mid+1,postr-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        in[a]=i;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&post[i]);
    go(1,n,1,n);
    for(int i:pre) printf("%d ",i);
    return 0;
}