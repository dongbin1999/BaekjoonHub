#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int k[1001];

int main(){
    int n,q,U,V;scanf("%d%d%d%d",&n,&q,&U,&V);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    while(q--){
        int c,a,b;scanf("%d%d%d",&c,&a,&b);
        if(c)k[a]=b;
        else{
            int ans=-2e9;
            vector<int> dp(n+1);
            for(int i=a;i<=b;i++){
                dp[i]+=max(0,dp[i-1])+U*k[i]+V;
                ans=max(ans,dp[i]);
            }
            printf("%d\n",ans-V);
        }
    }
}