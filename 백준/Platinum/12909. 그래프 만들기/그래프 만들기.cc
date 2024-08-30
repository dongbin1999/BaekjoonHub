#include<bits/stdc++.h>
using namespace std;

int dp[52][101];

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=1;i<n;i++)scanf("%d",&v[i]);
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int d=0;d<(n-1)*2;d++)
            for(int deg=1;deg<=n-1;deg++)
                if(d+deg<=(n-1)*2)
                    dp[i+1][d+deg]=max(dp[i+1][d+deg],dp[i][d]+v[deg]);
    printf("%d",dp[n][(n-1)*2]);
}