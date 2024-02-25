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
//간선 입력 전에, adj 배열 1e9로 초기화.
int adj[101][101];
int dp[101][101];
vector<int> route;

void back(int s,int e)
{
    if(dp[s][e]==1e9) return;
    if(dp[s][e]==e)
    {
        route.push_back(s);
        route.push_back(e);
        return;
    }
    back(s,dp[s][e]);
    route.pop_back();
    back(dp[s][e],e);
    return;
}

void floyd_warshall(int n)
{
    for(int via=1;via<=n;via++)
        for(int s=1;s<=n;s++)
            for(int e=1;e<=n;e++)
                if(s!=e&&s!=via&&e!=via)
                {
                    if(adj[s][e]>adj[s][via]+adj[via][e])
                        adj[s][e]=min(adj[s][e],adj[s][via]+adj[via][e]),dp[s][e]=via;
                }

    //출력. adj[i][j] : i->j에 필요한 최소 비용.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",adj[i][j]==1e9?0:adj[i][j]);
        printf("\n");
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            route.clear();
            back(i,j);
            printf("%d ",route.size());
            for(int k:route) printf("%d ",k);
            printf("\n");
        }
    return;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        fill(adj[i],adj[i]+1+n,1e9), fill(dp[i],dp[i]+1+n,1e9);
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a][b]=min(adj[a][b],c);
        dp[a][b]=b;
    }
    floyd_warshall(n);
    return 0;
}