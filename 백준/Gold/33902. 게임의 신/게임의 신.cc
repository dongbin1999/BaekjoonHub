#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int go(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];
    int ret=0;
    for(int z=x+1;z<=y;z++)
        if(gcd(z,x)==1)ret|=!go(z,y);
    return dp[x][y]=ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int x,y;scanf("%d%d",&x,&y);
    printf(go(x,y)?"khj20006":"putdata");
}