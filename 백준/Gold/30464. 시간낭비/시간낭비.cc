#include <bits/stdc++.h>
using namespace std;
int a[200001],dp[3][200001],n;
int go(int dir,int idx){
    if(idx==n)return 0;
    if(idx>n||idx<1||!a[idx])return -1e9;
    int ret=-1e9;
    if(dp[dir][idx]>-1e9)return dp[dir][idx];
    for(int ndir=dir;ndir<3;ndir++){
        int nidx=ndir==1?idx-a[idx]:idx+a[idx];
        ret=max(ret,go(ndir,nidx)+1);
    }
    return dp[dir][idx]=ret;
}

int main(){
    scanf("%d",&n);
    memset(dp,-0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%d",max(go(0,1),-1));
}