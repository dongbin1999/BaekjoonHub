#include <bits/stdc++.h>
using namespace std;

bool dp[5001][5001][3];
char s[5003];

int main(){
    scanf("%s",s+1);int n=strlen(s+1);
    dp[0][0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(s[i+1]=='('){
                dp[i+1][j+1][0]|=dp[i][j][0];
                if(j)dp[i+1][j-1][1]|=dp[i][j][0]|dp[i][j][1];
                dp[i+1][j+1][2]|=dp[i][j][1]|dp[i][j][2];
            }
            else{
                if(j)dp[i+1][j-1][0]|=dp[i][j][0];
                dp[i+1][j+1][1]|=dp[i][j][0]|dp[i][j][1];
                if(j)dp[i+1][j-1][2]|=dp[i][j][1]|dp[i][j][2];
            }
        }
    }
    if(dp[n][0][0]||dp[n][0][1]||dp[n][0][2])printf("possible");
    else printf("impossible");
    return 0;
}