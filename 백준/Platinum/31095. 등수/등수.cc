#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[5001][5001],cmb[5001][5001],b[5001];

ll all(ll n);
ll go(ll n,ll k){
    if(dp[n][k]!=-1)return dp[n][k];
    ll ret=0;
    if(k==1){
        for(int i=0;i<=n-1;i++)ret+=cmb[n-1][i]*all(n-1-i)%mod;
    }
    else{
        ll d=cmb[n-1][k-1]*all(k-1)%mod;
        ret=d*go(n-k+1,1);
    }
    return dp[n][k]=ret%mod;
}

ll all(ll n){
    if(!n)return b[n]=1;
    if(b[n]!=-1)return b[n];
    ll ret=0;for(int i=1;i<=n;i++)ret+=go(n,i);
    return b[n]=ret%mod;
}

int main(){
    cmb[0][0]=1;for(int i=1;i<=5000;i++)for(int j=0;j<=i;j++)cmb[i][j]=(cmb[i-1][j]+(j?cmb[i-1][j-1]:0ll))%mod;
    memset(b,-1,sizeof(b)),memset(dp,-1,sizeof(dp));
    int t;scanf("%d",&t);
    while(t--){
        int n,k;scanf("%d%d",&n,&k);
        printf("%lld\n",go(n,k));
    }
}