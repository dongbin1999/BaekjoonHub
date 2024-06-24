#include<bits/stdc++.h>
using namespace std;

int a[101],c[101];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    vector<int> dp(10001);
    for(int x=0;x<n;x++){
        auto nx=dp;
        for(int i=c[x];i<=10000;i++)nx[i]=max(nx[i],dp[i-c[x]]+a[x]);
        dp=nx;
    }
    int ans=1e9;
    for(int i=0;i<=10000;i++)if(dp[i]>=m)ans=min(ans,i);
    printf("%d",ans);
    return 0;
}