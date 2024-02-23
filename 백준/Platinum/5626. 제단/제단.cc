#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[10001][5001];//i번째 제단 높이가 j인 경우의 수

int main(){
    int n;scanf("%d",&n);
    dp[1][0]=1;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        int mx=min(i-1,n-i);
        if(x>mx)return !printf("0");
        else if(x==-1){
            for(int p=0;p<=mx;p++)for(int d=-1;d<=1;d++)
                if(0<=p+d&&p+d<=n/2)dp[i][p]=(dp[i][p]+dp[i-1][p+d])%mod;
        }
        else{
            for(int d=-1;d<=1;d++)
                if(0<=x+d&&x+d<=n/2)dp[i][x]=(dp[i][x]+dp[i-1][x+d])%mod;
        }
    }
    printf("%d",dp[n][0]);
}