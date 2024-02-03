#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1000000009;

pll dp[1000][129];

int main(){
    int k,b;scanf("%d%d",&k,&b);
    //경우의 수, 1의 개수
    dp[0][0]={1,0};
    ll d=1;
    for(int i=0;i<b;i++){
        for(int j=0;j<k;j++){
            //0 붙이기
            dp[j][i+1].first=(dp[j][i+1].first+dp[j][i].first)%mod;
            dp[j][i+1].second=(dp[j][i+1].second+dp[j][i].second)%mod;
            //1 붙이기
            ll nr=(d+j)%k;
            dp[nr][i+1].first=(dp[nr][i+1].first+dp[j][i].first)%mod;
            dp[nr][i+1].second=(dp[nr][i+1].second+dp[j][i].first+dp[j][i].second)%mod;
        }
        d=(d*2)%k;
    }
    printf("%lld",dp[0][b].second);
    return 0;
}