#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
/*
정삼각형 블록 4개를 위,오른쪽순으로 1,2,3,4번으로 가정.
문제의 두 번째 그림을 예시로 들면,
첫 번째 도형 : 1, 두 번째 도형 : 23, 세 번째 도형 : 34, 네 번째 도형 : 13.
*/
int dp[100001][2];//1/0 : 2번블록이 이미 채워진거/안채워진거.근데 채우려면 보라색 블록으로만 채워야함.

int solution(int n, vector<int> tops) {
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        if(tops[i]){
            dp[i+1][0]=(dp[i+1][0]+dp[i][0]*3)%mod;//123
            dp[i+1][1]=(dp[i+1][1]+dp[i][0]*1)%mod;//1234
            dp[i+1][0]=(dp[i+1][0]+dp[i][1]*2)%mod;//13
            dp[i+1][1]=(dp[i+1][1]+dp[i][1]*1)%mod;//134
        }
        else{
            dp[i+1][0]=(dp[i+1][0]+dp[i][0]*2)%mod;//23
            dp[i+1][1]=(dp[i+1][1]+dp[i][0]*1)%mod;//234
            dp[i+1][0]=(dp[i+1][0]+dp[i][1]*1)%mod;//3
            dp[i+1][1]=(dp[i+1][1]+dp[i][1]*1)%mod;//34
        }
    }
    return (dp[n][0]+dp[n][1])%mod;
}