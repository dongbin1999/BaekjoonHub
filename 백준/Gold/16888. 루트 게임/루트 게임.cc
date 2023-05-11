#include <bits/stdc++.h>
int dp[1000001];

using namespace std;
bool f(int x){
    if(dp[x]>-1) return dp[x];
    int y=sqrt(x);
    if(y*y==x) return dp[x]=1;
    for(int i=1;i*i<=x;i++)
        if(!f(x-i*i)) return dp[x]=1;
    return dp[x]=0;
}

int main() {
    memset(dp,-1,sizeof(dp));
    int n,x;scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        printf(f(x)?"koosaga\n":"cubelover\n");
    }
    return 0;
}