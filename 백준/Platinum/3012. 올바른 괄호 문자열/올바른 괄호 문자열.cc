#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e5;
#define add(a,b)((a+b)%mod+(!!((a+b)/mod))*mod)

char s[202];
ll dp[202][202];
map<pair<char,char>,ll> ma;
ll go(int l,int r){
    if(l-1==r)return 1;
    if(dp[l][r]>=0)return dp[l][r];
    if(l+1==r)return dp[l][r]=ma[{s[l],s[r]}];
    ll ret=go(l+1,r-1)*ma[{s[l],s[r]}];
    for(int m=l+1;m+1<r;m+=2){
        ll x=ma[{s[l],s[m]}]*go(l+1,m-1)*go(m+1,r);
        ret=add(ret,x);
    }
    return dp[l][r]=add(ret,0);
}

int main(){
    ma[{'(',')'}]=ma[{'{','}'}]=ma[{'[',']'}]=
    ma[{'?',')'}]=ma[{'?','}'}]=ma[{'?',']'}]=
    ma[{'(','?'}]=ma[{'{','?'}]=ma[{'[','?'}]=1;ma[{'?','?'}]=3;
    int n;scanf("%d %s",&n,s+1);
    if(n&1)return !printf("0");
    memset(dp,-1,sizeof(dp));
    ll ans=go(1,n);
    if(ans>=mod)printf("%0*lld",5,ans%mod);
    else printf("%lld",ans);
    return 0;
}