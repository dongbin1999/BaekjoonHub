#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[2][2][5001][5001];//방향/답에 포함 되는가?/현재 가장 큰 숫자/수열 길이

int main(){
    int n,k;scanf("%d%d",&n,&k);
    ll ans=0;
    dp[0][1][n-1][2]=dp[1][1][n-1][2]=1;//n 옆에는 항상 n-1이 붙어 있어야 한다.
    for(int x=n-1;x>=1;x--)
        for(int len=2;len<=k;len++)
            for(int b=0;b<2;b++){
                //printf("dp[%d][%d][%d]=%lld\n",b,x,len,dp[b][1][x][len]);
                ans=(ans+dp[b][1][x][len]*(ll)(k-len+1))%mod; //0으로 나머지 공간 채우고 마무리.
                for(int i=0;i<2;i++){
                    if(x>len)dp[!b][1][x-len][len+1]=(dp[!b][1][x-len][len+1]+dp[b][i][x][len])%mod;//방향 전환.
                    if(x>1)dp[b][1][x-1][len+1]=(dp[b][1][x-1][len+1]+dp[b][i][x][len])%mod;
                    if(x>2)dp[b][0][x-2][len]=(dp[b][0][x-2][len]+dp[b][i][x][len])%mod;
                }
            }
    printf("%lld",ans);
}