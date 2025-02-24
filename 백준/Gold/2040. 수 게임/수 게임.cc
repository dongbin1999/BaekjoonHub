#include<bits/stdc++.h>
using namespace std;
int n,dp[2][3000],v[3000];
int go(int x,bool b){
    if(x==-1)return 0;
    if(dp[b][x]<1e9)return dp[b][x];
    int ret=1e9,sum=0;
    for(int i=x;i>=0;i--)
        sum+=v[i],ret=min(ret,sum-go(i-1,!b));
    return dp[b][x]=ret;
}
void solve(){
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    memset(dp,0x3f,sizeof(dp));
    int ans=go(n-1,0);
    if(ans<0)printf("A\n");
    else if(ans==0)printf("D\n");
    else printf("B\n");
}

int main(){
    scanf("%d",&n);
    int tc=3;
    while(tc--)solve();
}