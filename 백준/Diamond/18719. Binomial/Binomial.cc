#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=20;

int dp[1<<sz][sz+1];

void solve(){
    int n;scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    while(n--){
        int x;scanf("%d",&x);
        dp[x][0]++;
    }
    for(int i=0;i<sz;i++)for(int bit=0;bit<1<<sz;bit++){
        if(bit>>i&1)dp[bit^(1<<i)][i+1]+=dp[bit][i];
        dp[bit][i+1]+=dp[bit][i];
    }
    ll ans=0;
    for(int i=0;i<1<<sz;i++)ans+=(ll)dp[i][0]*dp[i][sz];
    printf("%lld\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}