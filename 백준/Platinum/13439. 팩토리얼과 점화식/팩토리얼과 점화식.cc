#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
unordered_map<int,int> dp[101][1001];
unordered_map<int,int> go(int n,int k){
    if(!n) return {};
    if(!dp[k][n].empty())return dp[k][n];
    if(!k){
        unordered_map<int,int> ma;
        int nn=n;
        for(int i=2;i*i<=nn;i++)while(n%i==0)ma[i]++,n/=i;
        if(n>1)ma[n]++;
        return dp[k][nn]=ma;
    }
    auto l=go(n,k-1),r=go(n-1,k);
    for(auto [a,b]:r)l[a]=(l[a]+b)%mod;
    return dp[k][n]=l;
}


int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    ll ans=1;
    for(auto [a,b]:go(n,k))
        ans=(ans*(ll)(b+1)%mod)%mod;
    printf("%lld",ans);
}