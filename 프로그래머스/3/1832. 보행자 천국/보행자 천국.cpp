#include<bits/stdc++.h>
using namespace std;

int MOD = 20170805;
int dp[2][501][501];

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++){
        if(i+1<m&&city_map[i][j]!=1)dp[0][i+1][j]=(dp[0][i+1][j]+dp[0][i][j])%MOD;
        if(j+1<n&&city_map[i][j]!=1)dp[1][i][j+1]=(dp[1][i][j+1]+dp[1][i][j])%MOD;
        if(i+1<m&&city_map[i][j]==0)dp[0][i+1][j]=(dp[0][i+1][j]+dp[1][i][j])%MOD;
        if(j+1<n&&city_map[i][j]==0)dp[1][i][j+1]=(dp[1][i][j+1]+dp[0][i][j])%MOD;
    }
    
    return (dp[0][m-1][n-1]+dp[1][m-1][n-1])%MOD;
}