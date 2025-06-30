#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2][300000];

int main(){
    int n;scanf("%d",&n);
    deque<ll> v(n);
    int s=-1;ll sum=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
        if(v[i])sum+=v[i],s=i;
    }
    if(s==-1)return !printf("%lld",(ll)n/2);
    while(s--)v.push_back(v.front()),v.pop_front();
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<n;i++){
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
        if(!v[i])dp[1][i]=dp[0][i-1]+1;
    }
    printf("%lld",max(dp[0][n-1],dp[1][n-1])+sum);
}