#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;
vector<pic> graph[1001];

int main(){
    int c;scanf("%d",&c);
    vector<char> v(c);
    for(int i=0;i<c;i++)scanf(" %c",&v[i]);
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int x,y;char z;scanf(" %d %d %c",&x,&y,&z);
        graph[x].push_back({y,z}),graph[y].push_back({x,z});
    }
    vector<int> dp(n+1,-1e9);dp[1]=0;
    for(auto z:v){
        vector<int> tmp=dp;
        for(int i=1;i<=n;i++)
            for(auto [nx,nz]:graph[i])
                tmp[nx]=max(tmp[nx],dp[i]+(nz==z?10:0));
        dp=tmp;
    }
    printf("%d",*max_element(dp.begin(),dp.end()));
    return 0;
}