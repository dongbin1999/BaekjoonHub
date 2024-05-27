#include<bits/stdc++.h>
using namespace std;
int c[2001],sum[2002],dp[2001][2001],n;

//동전이 x개 남았고,이전 플레이어가 p개 가져감.
int go(int x,int p){
    if(!x||!p)return 0;
    if(dp[x][p]!=-1)return dp[x][p];
    int ret=go(x,p-1);//이번 턴에 [1~2(p-1)]개 가져가는 경우는, 여기서 다 체크했음.
    if(p*2-1<=x)ret=max(ret,sum[n-x+1]-go(x-(p*2-1),p*2-1));
    if(p*2<=x)ret=max(ret,sum[n-x+1]-go(x-p*2,p*2));
    return dp[x][p]=ret;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=n;i>=1;i--)sum[i]=sum[i+1]+c[i];
    memset(dp,-1,sizeof(dp));
    printf("%d",go(n,1));
    return 0;
}