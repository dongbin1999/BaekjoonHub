#include <bits/stdc++.h>
using namespace std;

int dp[101][501];

int r(int h,int w){
    if(h>w)swap(h,w);
    if(dp[h][w]!=-1)return dp[h][w];
    if(h==w)return dp[h][w]=1;
    int ret=1e9;
    for(int i=1;i<h;i++)ret=min(ret,r(i,w)+r(h-i,w));
    for(int i=1;i<w;i++)ret=min(ret,r(h,w-i)+r(h,i));
    return dp[h][w]=ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int a,b;scanf("%d%d",&a,&b);
    if(a>b)swap(a,b);
    int ans=0;
    while(b>=5*a)ans++,b-=a;
    printf("%d",ans+r(a,b));
    return 0;
}