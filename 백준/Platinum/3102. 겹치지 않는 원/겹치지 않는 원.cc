#include <bits/stdc++.h>
using namespace std;

int dp[301][301],line[301][301];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);x+=100;
        line[x-y][x+y]=1;
    }
    int ans=0;
    for(int len=2;len<=200;len++)for(int l=0,r=l+len;r<=300;l++,r++)
            for(int i=l;i<r;i++)
                dp[l][r]=max(dp[l][r],dp[l][i]+dp[i][r]+line[l][r]),ans=max(ans,dp[l][r]);
    printf("%d",n-ans);
    return 0;
}