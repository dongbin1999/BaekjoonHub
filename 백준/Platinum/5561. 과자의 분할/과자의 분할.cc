#include<bits/stdc++.h>
using namespace std;

int dp[2][5002],tmp[2][5002];

int main(){
    memset(dp,0x3f,sizeof(dp));
    int n;scanf("%d",&n);
    int half=n/2;n--;
    dp[0][0]=dp[1][1]=0;
    while(n--){
        int x;scanf("%d",&x);
        memset(tmp,0x3f,sizeof(tmp));
        for(int i=0;i<=half;i++){
            tmp[0][i]=min({tmp[0][i],dp[0][i],dp[1][i]+x});
            tmp[1][i+1]=min({tmp[1][i+1],dp[0][i]+x,dp[1][i]});
        }
        memcpy(dp,tmp,sizeof(dp));
    }
    printf("%d\n",min(dp[0][half],dp[1][half]));
    return 0;
}