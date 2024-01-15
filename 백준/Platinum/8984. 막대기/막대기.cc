#include <bits/stdc++.h>
using namespace std;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
#define idx(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()
typedef long long ll;
typedef pair<int,int> pii;

unordered_map<int,ll> dp[2];

int main(){
    int n;ll l;scanf("%d%lld",&n,&l);
    vector<pii> v;
    for(int i=0;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(auto [x,y]:v){
        ll px=dp[0][x],py=dp[1][y];
        dp[0][x]=max(dp[0][x],py+abs(x-y)+l);
        dp[1][y]=max(dp[1][y],px+abs(x-y)+l);
        ans=max({ans,dp[0][x],dp[1][y]});
    }
    printf("%lld",ans);
    return 0;
}