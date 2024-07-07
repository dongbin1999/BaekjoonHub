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

struct element
{
    int a,b,c;
};

bool operator<(element a,element b)
{
    return a.c>b.c;
}

int u[10001];
element e[100001];

int find(int a)
{
    if(u[a]<0)return a;
    return u[a]=find(u[a]);
}

bool merge(int a,int b)
{
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}


int main()
{
    int n,m;scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        e[i]={a,b,c};
    }
    sort(e+1,e+1+m);
    fill(u,u+1+n,-1);
    int a,b;scanf("%d %d",&a,&b);
    for(int i=1;i<=m;i++)
    {
        merge(e[i].a,e[i].b);
        if(find(a)==find(b)) return !printf("%d",e[i].c);
    }
    return 0;
}