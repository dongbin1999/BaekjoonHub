#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc=1;
    while(1){
        int n;scanf("%d",&n);
        if(!n) break;
        printf("%d. ",tc++);
        vector<int> t(3,1e9);
        vector<vector<int>> dp(n,t),v(n,t);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
        dp[0][1]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]);
                if(j>0&&i>0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(j<2&&i>0)dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                dp[i][j]+=v[i][j];
            }
        }
        printf("%d\n",dp[n-1][1]);
    }
    return 0;
}