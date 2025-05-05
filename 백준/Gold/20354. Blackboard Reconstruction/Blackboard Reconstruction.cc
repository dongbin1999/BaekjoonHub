#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;
pii dp[1001][10001];

int main(){
    int s,e;scanf("%d%d",&s,&e);
    vector<int> v(e);
    multiset<int> se;
    memset(dp,-1,sizeof(dp));
    dp[0][0]={0,0};
    for(int i=0;i<e;i++){
        scanf("%d",&v[i]),se.insert(v[i]);
        for(int j=0;j<=s;j++)dp[i+1][j]=dp[i][j];
        for(int nx=v[i];nx<=s;nx++)
            if(dp[i][nx-v[i]].first!=-1)dp[i+1][nx]={i,nx-v[i]};
    }
    int x=3,y=1;
    vector<arr>ans;
    while(1){
        auto [pe,ps]=dp[e][s];
        ans.push_back({y,x,s-ps}),y=x,x++;
        se.erase(se.find(s-ps)),e=pe,s=ps;
        if(!s)break;
    }
    ans.back()[1]=2,x-=2;
    for(auto r:se)ans.push_back({2,++x,r});
    printf("%d\n",x);
    for(auto [a,b,c]:ans)printf("%d %d %d\n",a,b,c);
}