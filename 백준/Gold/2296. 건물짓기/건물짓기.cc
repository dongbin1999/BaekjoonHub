#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,3> tup;
const ll mod=1e9+7;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int dp[1001];

void solve(){
    int n;scanf("%d",&n);
    vector<tup> v(n);
    for(auto &[x,y,c]:v)scanf("%d%d%d",&x,&y,&c);
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        dp[i]+=v[i][2];
        for(int j=i+1;j<n;j++)
            dp[j]=max(dp[j],v[i][1]<v[j][1]?dp[i]:0);
    }
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,dp[i]);

    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i]+=v[i][2];
        for(int j=i+1;j<n;j++)
            dp[j]=max(dp[j],v[i][1]>v[j][1]?dp[i]:0);
    }
    for(int i=0;i<n;i++)ans=max(ans,dp[i]);
    printf("%d",ans);
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}