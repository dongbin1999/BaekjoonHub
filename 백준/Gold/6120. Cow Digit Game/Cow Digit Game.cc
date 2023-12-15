#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
bool win(int x){
    if(x<0)return 0;
    if(!x)return 0;
    if(dp[x]!=-1)return dp[x];
    vector<int> v;int xx=x;
    while(xx){
        if(xx%10)v.push_back(xx%10);
        xx/=10;
    }
    return dp[x]=!win(x-*min_element(v.begin(),v.end()))|!win(x-*max_element(v.begin(),v.end()));
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        printf(win(x)?"YES\n":"NO\n");
    }
}