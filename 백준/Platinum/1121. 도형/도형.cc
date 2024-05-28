#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=50001;
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(11,vector<ll>(mx+1)));
    dp[1][0][0]=1;
    int k;scanf("%d",&k);
    for(auto len:v){
        auto tmp=dp;
        for(int i=0;i<k;i++)for(int j=0;j<=mx;j++){
            ll nx=min(mx,j+len);
            tmp[len<j][i+1][nx]+=dp[0][i][j]+dp[1][i][j];
        }
        dp=tmp;
    }
    ll ans=0;
    for(int i=0;i<=mx;i++)ans+=dp[1][k][i];
    printf("%lld",ans);
    return 0;
}