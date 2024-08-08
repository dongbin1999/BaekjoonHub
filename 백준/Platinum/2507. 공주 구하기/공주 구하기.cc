#include<bits/stdc++.h>
using namespace std;
const int mod=1000;

//가는 길에 밟고 있는 발판이 x, 돌아오는 길에 밟고 있는 발판이 y일때, 경우의 수?
int dp[501][501],p[501],d[501],g[501];

int main(){
    int n;scanf("%d",&n);
    dp[1][0]=1;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i],&d[i],&g[i]);
    for(int x=1;x<n;x++)for(int y=0;y<=n;y++)for(int z=max(x,y)+1;z<=n;z++){
        //x->z로 점프.
        if(z<n&&p[x]+d[x]>=p[z])dp[z][y]=(dp[z][y]+dp[x][y])%mod;
        //y<-z로 점프.
        if(g[z]&&p[z]-d[z]<=p[y])dp[x][z]=(dp[x][z]+dp[x][y])%mod;
    }
    int ans=0;
    for(int i=1;i<n;i++)if(p[i]+d[i]>=p[n])ans=(ans+dp[i][n])%mod;
    printf("%d",ans);
    return 0;
}