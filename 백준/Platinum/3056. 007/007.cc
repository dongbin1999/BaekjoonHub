#include <bits/stdc++.h>
using namespace std;

double dp[1<<20][2];

int main(){
    int n;scanf("%d",&n);
    dp[0][0]=100.0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++){
            int x;scanf("%d",&x);
            for(int bit=0;bit<1<<n;bit++){
                if(bit>>j&1)continue;
                dp[bit+(1<<j)][i&1]=max(dp[bit+(1<<j)][i&1],dp[bit][i&1^1]*x/100);
            }
        }
    printf("%.6lf",dp[(1<<n)-1][n&1]);
    return 0;
}