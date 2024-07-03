#include<bits/stdc++.h>
using namespace std;
#define add(x) (x+1==n?0:x+1)
#define mi(x) (!x?n-1:x-1)
int a[1000],dp[2][101][1000][1000],n;
int go(bool turn,int t,int l,int r){
    if(dp[turn][t][l][r]>-1e9)return dp[turn][t][l][r];
    if(l==r)return dp[turn][t][l][r]=a[l];
    int ret=-2e9;
    if(((a[l]<<1)|turn)<=(t<<1))ret=max(ret,a[l]+go(turn,t-a[l],add(l),r));
    else ret=max(ret,a[l]-go(!turn,a[l]-t,add(l),r));
    if(((a[r]<<1)|turn)<=(t<<1))ret=max(ret,a[r]+go(turn,t-a[r],l,mi(r)));
    else ret=max(ret,a[r]-go(!turn,a[r]-t,l,mi(r)));
    return dp[turn][t][l][r]=ret;
}

int main(){
    memset(dp,-0x3f,sizeof(dp));
    scanf("%d",&n);
    int ans=0,sum=0;
    for(int i=0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
    if(n==1)return !printf("%d",a[0]);

    for(int i=0;i<n;i++){
        int x=a[i];sum-=a[i];
        int z=go(1,a[i],add(i),mi(i));
        int y=(sum+z)/2;x+=sum-y;
        ans=max(ans,x);
        sum+=a[i];
    }
    printf("%d",ans);
}