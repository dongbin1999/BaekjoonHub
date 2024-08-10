#include<bits/stdc++.h>
using namespace std;
#define f(x) (min(s[x]-'A',26-(s[x]-'A')))

int dp[2][1000][1000],allA[1000][1000];

void solve(){
    memset(dp,0x3f,sizeof(dp));memset(allA,-1,sizeof(allA));
    string s;cin>>s;
    dp[0][0][0]=dp[1][0][0]=f(0);
    int n=s.size();
    for(int len=1;len<n;len++)for(int l=0,r=(l+len-1)%n;l<n;l++,r=(r+1)%n){
        int nl=(l+n-1)%n,nr=r;//l->l
        dp[0][nl][nr]=min(dp[0][nl][nr],dp[0][l][r]+1+f(nl));
        nl=l,nr=(r+1)%n;//l->r
        dp[1][nl][nr]=min(dp[1][nl][nr],dp[0][l][r]+len+f(nr));
        nl=(l+n-1)%n,nr=r;//r->l
        dp[0][nl][nr]=min(dp[0][nl][nr],dp[1][l][r]+len+f(nl));
        nl=l,nr=(r+1)%n;//r->r
        dp[1][nl][nr]=min(dp[1][nl][nr],dp[1][l][r]+1+f(nr));
    }
    for(int l=0;l<n;l++){
        int r=l;
        while(allA[l][r]==-1&&s[r]=='A')
            allA[l][r]=1,r=(r+1)%n;
    }
    int ans=2e9;
    for(int len=1;len<=n;len++)for(int l=0,r=(l+len-1)%n;l<n;l++,r=(r+1)%n)
        if(len==n)ans=min({ans,dp[0][l][r],dp[1][l][r]});
        else if(allA[r+1][(l+n-1)%n]==1)ans=min({ans,dp[0][l][r],dp[1][l][r]});

    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}