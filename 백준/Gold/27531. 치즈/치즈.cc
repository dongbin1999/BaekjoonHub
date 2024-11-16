#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
vector<pii> graph[200001];
int vis[200001];
vector<ll> v;
void go(int cur,int pre=-1){
    if(vis[cur])return;vis[cur]=1;
    auto [nx,cost]=graph[cur][0];
    if(nx!=pre)v.push_back(cost),go(nx,cur);
    else{
        nx=graph[cur][1].first,cost=graph[cur][1].second;
        v.push_back(cost),go(nx,cur);
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;ll p;scanf("%d%d%lld",&a,&b,&p);
        graph[a].push_back({b,p});
        graph[b].push_back({a,p});
    }
    for(int i=1;i<=n;i++)sort(graph[i].begin(),graph[i].end());
    ll ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        v.clear(),go(i);
        cnt+=v.size();
        int m=v.size();
        if(m==1){ans+=v[0];continue;}
        vector<vector<ll>> dp(2,vector<ll>(m,1e10));
        dp[0][0]=v[m-1],dp[1][1]=v[0];
        for(int j=1;j<m;j++)
            for(int k=0;k<2;k++){
                dp[k][j]=min(dp[k][j],dp[k][j-1]+v[j-1]);
                if(j>1)dp[k][j]=min(dp[k][j],dp[k][j-2]+v[j-1]);
            }
        ans+=min({dp[1][m-1],dp[0][m-2],dp[0][m-1]});
    }
    printf("%lld",ans);
}