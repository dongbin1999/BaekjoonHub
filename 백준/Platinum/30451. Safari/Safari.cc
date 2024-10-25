#include<bits/stdc++.h>
using namespace std;
typedef array<int,4> arr;

int main(){
    int n;scanf("%d",&n);
    vector<arr> p(n+1);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i][2],&p[i][3]);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i][1],&p[i][0]);
    sort(p.begin(),p.end());
    vector<int> dp(n+1,-1e9);dp[0]=0;
    int ans=0;
    for(int i=0;i<n;i++)for(int j=i+1;j<=n;j++){
        auto [r,l,x,y]=p[i];auto [nr,nl,nx,ny]=p[j];
        int d=abs(x-nx)+abs(y-ny);
        if(r+d>=nr)continue;
        int see=nr-max(nl,(r+d));
        dp[j]=max(dp[j],dp[i]+see);
        ans=max(ans,dp[j]);
    }
    printf("%d",ans);
}