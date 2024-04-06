#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> dp(m+1,1e9);dp[m]=0;
    while(n--){
        int x;scanf("%d",&x);
        vector<int> tmp(m+1,1e9);
        for(int i=0;i<=m;i++)tmp[x]=min(tmp[x],dp[i]+(m-i)*(m-i));
        for(int i=0;i+x+1<=m;i++)tmp[i+x+1]=min(tmp[i+x+1],dp[i]);
        dp=tmp;
        //for(int i=0;i<=m;i++)printf("%d ",dp[i]==1e9?-1:dp[i]);printf("\n");
    }
    printf("%d",*min_element(dp.begin(),dp.end()));
    return 0;
}