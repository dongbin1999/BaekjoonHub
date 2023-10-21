#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int dp[501][501];

bool go(int x,int y){
    if(x<0||y<0)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    bool ret=0;
    ret|=!go(x-a,y);ret|=!go(x,y-a);
    ret|=!go(x-b,y);ret|=!go(x,y-b);
    ret|=!go(x-c,y);ret|=!go(x,y-c);
    return dp[x][y]=ret;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int x,y;scanf("%d%d",&x,&y);
    printf("%c\n",!go(x,y)+'A');
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    int tc=5;while(tc--)solve();
    return 0;
}