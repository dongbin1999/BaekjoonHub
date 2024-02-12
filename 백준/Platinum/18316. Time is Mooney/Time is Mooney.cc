#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];

int main(){
    int n,m,c;scanf("%d%d%d",&n,&m,&c);
    vector<int> moony(n+1),dp(n+1,-1e9);dp[1]=0;
    for(int i=1;i<=n;i++)scanf("%d",&moony[i]);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    int ans=0;
    for(int t=0;t<1000;t++){
        vector<int> tmp(n+1,-1e9);
        for(int i=1;i<=n;i++)for(auto nx:graph[i])
            tmp[nx]=max(tmp[nx],dp[i]+moony[nx]-c*(t+t+1));
        dp=tmp;
        ans=max(ans,dp[1]);
    }
    printf("%d",ans);
    return 0;
}