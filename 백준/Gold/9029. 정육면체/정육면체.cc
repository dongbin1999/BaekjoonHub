#include<bits/stdc++.h>
using namespace std;
int dp[201][201][201];

int go(int a,int b,int c){
    if(a==b&&b==c)return 0;
    if(c<a)swap(c,a);if(c<b)swap(c,b);if(b<a)swap(b,a);
    if(dp[a][b][c]<1e9)return dp[a][b][c];
    int mn=1e9;
    for(int i=1;i+i<=a;i++)mn=min(mn,go(i,b,c)+go(a-i,b,c)+1);
    for(int i=1;i+i<=b;i++)mn=min(mn,go(a,i,c)+go(a,b-i,c)+1);
    for(int i=1;i+i<=c;i++)mn=min(mn,go(a,b,i)+go(a,b,c-i)+1);
    return dp[a][b][c]=mn;
}

void solve(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",1+go(a,b,c));
}

int main(){
    memset(dp,0x3f,sizeof(dp));
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}