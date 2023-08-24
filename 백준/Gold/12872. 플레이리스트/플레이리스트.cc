#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define add(x,k) x=(x+k)%mod
ll dp[201][201];//i번째 칸까지 플레이리스트를 만드는데, 한번도 안써본 곡이 j개.
ll n,m,p;
ll go(ll i,ll j){
    if(dp[i][j]>=0)return dp[i][j];
    if(!i)return dp[i][j]=!j;
    ll ret=0;
    if(j)add(ret,go(i-1,j-1)*j);
    add(ret,go(i-1,j)*max(0ll,n-j-m));
    return dp[i][j]=ret;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&p);
    memset(dp,-1,sizeof(dp));
    printf("%lld",go(p,n));
    return 0;
}