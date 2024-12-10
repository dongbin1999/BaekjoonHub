#include<bits/stdc++.h>
using namespace std;
bool dp[1<<12][1441]={1};
int a[1441],to[12];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int s,e;scanf("%d%d",&s,&e);
        a[s]++,a[e]--;
    }
    for(int i=1;i<=1440;i++)a[i]+=a[i-1];for(int i=1;i<=1440;i++)a[i]+=a[i-1];
    for(int i=0;i<k;i++)scanf("%d",&to[i]);
    for(int t=0;t<1440;t++)
        for(int b=0;b<1<<k;b++){
            if(!dp[b][t])continue;
            dp[b][t+1]=1;
            for(int x=0;x<k;x++){
                if(b>>x&1)continue;
                int nb=b|(1<<x),nt=t+to[x];
                if(a[nt-1]-(t?a[t-1]:0)||nt>1440)continue;
                dp[nb][nt]=1;
            }
        }
    for(int i=0;i<=1440;i++)if(dp[(1<<k)-1][i])return !printf("GOOD");
    printf("BAD");
}