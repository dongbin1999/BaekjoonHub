#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002],need[1002][1002][2];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    int x=0;
    while(k--){
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i=b;i<=d;i++)need[a][i][0]++;//->아래
        for(int i=a;i<=c;i++)need[i][b][1]++;//->오른쪽
        x+=a==1&&b==1;
    }
    memset(dp,0x3f,sizeof(dp));dp[1][1]=x;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+need[i+1][j][0]);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+need[i][j+1][1]);
        }
    printf("%d",dp[n][m]);
}