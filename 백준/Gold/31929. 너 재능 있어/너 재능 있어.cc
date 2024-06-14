#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001],w[1001],l[1001],k;
int go(int x,int y){
    if(dp[x][y]>-1e9)return dp[x][y];
    if(!x&&!y)return dp[x][y]=0;
    if(!y)return dp[x][y]=go(x-1,y)+w[x];
    int ret=go(x,y-1),b=(ret+k*100000)%k;
    if(b)ret-=min(l[y],b);
    else ret-=l[y];
    if(!x)return dp[x][y]=ret;
    ret=max(ret,go(x-1,y)+w[x]);
    return dp[x][y]=ret;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&l[i]);
    scanf("%d",&k);
    memset(dp,-0x3f,sizeof(dp));
    printf("%d",go(n,m));
}