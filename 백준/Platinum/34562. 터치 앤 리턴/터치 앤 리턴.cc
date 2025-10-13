#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[20][20],c[20][1<<20],mn[21],dp[100001];
int n;
ll tsp(int cur,int bit){
    if(!(bit>>cur&1))return 1e9;
    if(c[cur][bit]!=-1)return c[cur][bit];
    ll ret=1e9;
    for(int nx=0;nx<n;nx++)
        ret=min(ret,tsp(nx,bit&~(1<<cur))+d[cur][nx]);
    return c[cur][bit]=ret;
}

int main(){
    int m,k;scanf("%d%d%d",&n,&m,&k);
    memset(c,-1,sizeof(c));c[0][1]=0;
    memset(mn,0x3f,sizeof(mn));
    memset(d,0x3f,sizeof(d));d[0][0]=0;
    memset(dp,-0x3f,sizeof(dp));dp[0]=0;

    while(m--){
        int a,b;ll C;scanf("%d%d%lld",&a,&b,&C);a--,b--;
        d[a][b]=d[b][a]=min(d[a][b],C);
    }

    for(int v=1;v<n;v++)for(int s=0;s<n;s++)for(int e=0;e<n;e++)
        d[s][e]=min(d[s][e],d[s][v]+d[v][e]);

    for(int i=1;i<1<<n;i++)for(int x=0;x<n;x++){
            int cnt=__builtin_popcount(i);
            mn[cnt]=min(mn[cnt],tsp(x,i)+d[x][0]);
        }

    for(int i=2;i<=n;i++)for(int j=0;j+mn[i]<=k;j++)
        dp[j+mn[i]]=max(dp[j+mn[i]],dp[j]+(i-1)*(i-1));

    ll ans=0;
    for(int i=0;i<=k;i++)ans=max(ans,dp[i]);
    printf("%lld",ans);
}