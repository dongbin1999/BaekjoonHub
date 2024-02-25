#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%MOD;a=a*a%MOD;b/=2;}return ret;}

int graph[501][501];

int main()
{
    int V,E,a,b,c;
    scanf("%d %d",&V,&E);
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            graph[i][j] = 1e9;
    while(E--)
    {
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b] = c;
    }

    for(int s=1;s<=V;s++)
        for(int e=1;e<=V;e++)
            for(int via=1;via<=V;via++)
                graph[s][e] = min(graph[s][e],graph[s][via]+graph[via][e]);
    int ans = 1e9;
    for(int i=1;i<=V;i++)
        ans=min(ans,graph[i][i]);
    printf("%d",ans==1e9?-1:ans);
    return 0;
}