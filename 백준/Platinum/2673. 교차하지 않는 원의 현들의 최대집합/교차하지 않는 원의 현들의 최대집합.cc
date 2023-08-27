#include <bits/stdc++.h>
using namespace std;

int dp[102][102],line[102][102];

int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        line[x][y]=line[y][x]=1;
    }
    for(int len=2;len<=100;len++)for(int l=1,r=l+len-1;r<=100;l++,r++)
        for(int i=l;i<r;i++)
            dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]+line[l][r]);
    printf("%d",dp[1][100]);
    return 0;
}