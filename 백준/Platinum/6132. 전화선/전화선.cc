#include<bits/stdc++.h>
using namespace std;
int dp[101],tmp[101];

int main(){
    int n,c;scanf("%d%d",&n,&c);
    while(n--){
        int h;scanf("%d",&h);
        memset(tmp,0x3f,sizeof(tmp));
        for(int i=1;i<=100;i++)for(int j=h;j<=100;j++)
            tmp[j]=min(tmp[j],dp[i]+abs(j-i)*c+(j-h)*(j-h));
        memcpy(dp,tmp,sizeof(dp));
    }
    int ans=INT_MAX;
    for(int i=1;i<=100;i++)ans=min(ans,dp[i]);
    printf("%d",ans);
    return 0;
}