#include<bits/stdc++.h>
using namespace std;
int dp[2][101][101],v[101],one;

int go(int l,int r,int o){
    if(dp[o&1][l][r]>-1)return dp[o&1][l][r];
    int ret=0;
    if(o)ret=!go(l,r,o-1);
    for(int i=l;i<=r;i++){
        bool ok=1;
        if(i>l)ok&=v[i]>v[i-1];
        if(i<r)ok&=v[i]>v[i+1];
        if(!ok)continue;
        if(one==i)ret=1;
        else if(one<i)ret|=!go(l,i-1,o+r-i);
        else ret|=!go(i+1,r,o+i-l);
    }
    return dp[o&1][l][r]=ret;
}

void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i]==1)one=i;
    }
    memset(dp,-1,sizeof(dp));
    printf(go(1,n,0)?"Alice\n":"Bob\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}