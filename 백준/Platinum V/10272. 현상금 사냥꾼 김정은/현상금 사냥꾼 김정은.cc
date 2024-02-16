#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
double dist(pii a,pii b){return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));}

void solve(){
    int n;scanf("%d",&n);
    vector<pii> v(n+2);
    for(int i=1;i<=n;i++)scanf("%d%d",&v[i].first,&v[i].second);
    vector<vector<double>> dp(n+2,vector(n+2,1e9));
    dp[1][1]=0;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
        dp[j][j+1]=min(dp[j][j+1],dp[i][j]+dist(v[i],v[j+1]));
        dp[i][j+1]=min(dp[i][j+1],dp[i][j]+dist(v[j],v[j+1]));
    }
    double ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,dp[i][n]+dist(v[i],v[n]));
    printf("%lf\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}