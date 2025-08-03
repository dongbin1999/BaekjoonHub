#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll k;
ll dp[5001][900];
ll go(ll x,ll i){
    if(i==-1)return 0;
    if(!x)return 1;
    if(dp[x][i]!=-1)return dp[x][i];
    ll ret=0;
    for(int j=i;j>=0;j--)
        if(v[j]<=x)
            ret+=go(x-v[j],j);
    return dp[x][i]=ret%k;
}

int main(){
    ll m;scanf("%lld%lld",&m,&k);
    for(ll i=1;i<=m;i++){
        ll s=0,x=i;
        while(x)s+=x%10,x/=10;
        if(i%s==0)v.push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld",go(m,v.size()-1));
}