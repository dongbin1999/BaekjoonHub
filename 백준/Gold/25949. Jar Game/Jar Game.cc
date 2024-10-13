#include<bits/stdc++.h>
using namespace std;

int dp[50][101][101][101];
int go(int t,int a,int b,int c){
    if(dp[t][a][b][c]<1e9)return dp[t][a][b][c];
    if(!max({a,b,c}))return 0;
    int mx=-1e9,eat;
    eat=min(a,t);if(eat)mx=max(mx,eat-go(t+1,a-eat,b,c));
    eat=min(b,t);if(eat)mx=max(mx,eat-go(t+1,a,b-eat,c));
    eat=min(c,t);if(eat)mx=max(mx,eat-go(t+1,a,b,c-eat));
    return dp[t][a][b][c]=mx;
}

int main(){
    memset(dp,0x3f,sizeof(dp));
    vector<int> v(3);
    for(int i=0;i<3;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int ans=go(1,v[0],v[1],v[2]);
    if(ans>0)printf("F");
    else if(ans<0)printf("S");
    else printf("D");
}