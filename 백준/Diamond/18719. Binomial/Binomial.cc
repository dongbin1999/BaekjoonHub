#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=20;
int dp[1<<sz];

void solve(){
    int n;scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    vector<int> v;;
    while(n--){
        int x;scanf("%d",&x);
        dp[x]++;v.push_back(x);
    }
    for(int i=0;i<sz;i++)for(int bit=0;bit<1<<sz;bit++)
            if(bit>>i&1)dp[bit]+=dp[bit^(1<<i)];
    ll ans=0;
    for(auto i:v)ans+=dp[i];
    printf("%lld\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}