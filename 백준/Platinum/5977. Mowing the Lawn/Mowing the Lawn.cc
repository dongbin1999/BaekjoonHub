#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> v(n+1),dp(n+1),sum(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]),sum[i]=sum[i-1]+v[i];
    deque<pli> dq={{0,0}};
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.front().second<i-k)dq.pop_front();
        ll x=sum[i]-dp[i-1];
        while(!dq.empty()&&dq.back().first>=x)dq.pop_back();
        dq.push_back({x,i});
        dp[i]=sum[i]-dq.front().first;
    }
    printf("%lld",dp[n]);
}