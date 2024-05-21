#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2002],b[2002];
ll dp[3][2001][2001];//0:A,B둘다-- 해야함 1:A만-- 가능 2:B만-- 가능
ll go(int x,int n,int m){
    if(n<0||m<0)return 1e12;
    if(dp[x][n][m]!=-1)return dp[x][n][m];
    if(!n&&!m)return dp[x][n][m]=0;
    ll A=a[n]-1,B=b[m]-1,pA=a[n+1]-1,pB=b[m+1]-1,ret=1e12;
    for(int X=0;X<3;X++)ret=min(ret,go(X,n-1,m-1)+A*B);
    if(x==1)ret=min(ret,go(1,n-1,m)+A*pB);
    else if(x==2)ret=min(ret,go(2,n,m-1)+pA*B);
    return dp[x][n][m]=ret;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
    printf("%lld",go(0,n,m));
}