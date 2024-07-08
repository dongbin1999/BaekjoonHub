#include <bits/stdc++.h>
using namespace std;

/*
1. 위아래 연결X, ] 가능 : 항상 3개 -> (ㄴ, r, = 모양으로 시작해서 계속 =로 연결된 상태)
2. 연결, ] 가능 : dp[0][i] -> 3번 상태에 - 연결을 하거나(위아래 2개), 1번 상태에 =연결로 이어가기
3. 연결, ] 불가능 : dp[1][i] -> 3번 상태에 ㄱ, 」, = 연결을 하거나, 1,2번 상태에 ]연결.
 * */
int dp[2][50001];

int main(){
    dp[0][2]=0,dp[1][2]=4;
    for(int i=3;i<=50000;i++){
        dp[1][i]+=dp[0][i-1]+dp[1][i-1]*3+3;
        dp[0][i]+=dp[1][i-1]*2+dp[0][i-1];
        dp[0][i]%=10007,dp[1][i]%=10007;
    }

    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        printf("%d %d\n",dp[1][x],(dp[0][x]+dp[1][x]+2)*x%10007);
    }
    return 0;
}