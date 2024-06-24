#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll dp[501][501];
pll v[501];
ll d(int a,int b){return abs(v[a].first-v[b].first)+abs(v[a].second-v[b].second);}
int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%lld%lld",&v[i].first,&v[i].second);
    memset(dp,0x3f,sizeof(dp)),dp[0][0]=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<=k;j++){
            for(int p=0;p<i;p++)
                if(j-(i-p-1)>=0)dp[i][j]=min(dp[i][j],dp[p][j-(i-p-1)]+d(p,i));
        }
    printf("%lld",dp[n-1][k]);
}