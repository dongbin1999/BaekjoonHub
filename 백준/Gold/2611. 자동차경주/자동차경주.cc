#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
typedef pair<int,int> pii;

pii dp[2][1001][1001];
vector<pii> graph[1001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<tup> v(m);
    for(auto &[p,q,r]:v){
        scanf("%d%d%d",&p,&q,&r);
        graph[p].push_back({q,r});
    }
    memset(dp,-0x3f,sizeof(dp));dp[0][1][0]={0,1};
    for(int i=0;i<n;i++)
        for(int cur=1;cur<=n;cur++){
            if(dp[0][cur][i].first<0)continue;
            for(auto [nx,cost]:graph[cur])
                dp[nx==1][nx][i+1]=max(dp[nx==1][nx][i+1],{dp[0][cur][i].first+cost,cur});
        }
    tup ans={-1,-1,-1};
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans=max(ans,{dp[1][i][j].first,i,j});
    printf("%d\n",ans[0]);
    auto [_,x,y]=ans;
    vector<int> trace={1,dp[1][x][y].second};
    x=trace.back(),y--;
    while(y){
        trace.push_back(dp[0][x][y].second);
        x=trace.back(),y--;
    }
    for(int i=trace.size()-1;i>=0;i--)printf("%d ",trace[i]);
}