#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> tree[100001];
ll dp[100001][3],ans;
void go(ll w,int node,int pa=-1){
    if(tree[node].size()==1){
        for(int i=0;i<3;i++)
            dp[node][i]=i?dp[node][i-1]*w:1;
        return ;
    }
    for(auto [nx,len]:tree[node]){
        if(nx==pa)continue;
        go(len,nx,node);
        ans+=dp[node][0]*dp[nx][2]+dp[node][2]*dp[nx][0]+dp[node][1]*dp[nx][1]*2;
        for(int i=0;i<3;i++)dp[node][i]+=dp[nx][i];
    }
    dp[node][2]+=dp[node][1]*w*2+w*w*dp[node][0];
    dp[node][1]+=dp[node][0]*w;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        ll a,b,l;scanf("%lld%lld%lld",&a,&b,&l);
        tree[a].push_back({b,l});
        tree[b].push_back({a,l});
    }
    for(int i=1;i<=n;i++)if(tree[i].size()==3){
        go(0,i);
        return !printf("%lld",ans);
    }
    return 0;
}