#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1000000007;
#define add(a,b) a=(a+b)%mod

pii v[100001];
int f[100001];
map<pii,int> out;
ll dp[100001][2][2];
ll go(int node,int exp,int res){
    if(!node)return exp==res;
    if(dp[node][exp][res]!=-1)return dp[node][exp][res];
    auto [le,ri]=v[node];
    ll ret[2][2]={0};
    for(int el=0;el<2;el++)for(int rl=0;rl<2;rl++)for(int er=0;er<2;er++)for(int rr=0;rr<2;rr++){
                    int e=out[{el,er}],r=out[{rl,rr}];
                    add(ret[e][r],go(le,el,rl)*go(ri,er,rr));
                }
    int stuck=f[node];
    if(stuck>=0){
        for(int e=0;e<2;e++)
            add(ret[e][stuck],ret[e][!stuck]),ret[e][!stuck]=0;
    }
    for(int e=0;e<2;e++)for(int r=0;r<2;r++)dp[node][e][r]=ret[e][r];
    return dp[node][exp][res];
}

int main(){
    out[{1,0}]=out[{0,1}]=out[{0,0}]=1,out[{1,1}]=0;
    memset(dp,-1,sizeof(dp));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&v[i].first,&v[i].second,&f[i]);
    printf("%lld",(go(1,1,0)+go(1,0,1))%mod);
    return 0;
}