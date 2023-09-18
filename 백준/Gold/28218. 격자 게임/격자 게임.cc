#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,k,dp[303][303];
char a[303][303];
vector<pii> go={{0,1},{1,0}};

bool f(int x,int y){
    if(x>n||y>m||a[x][y]=='#')return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    if(x==n&&y==m)return dp[x][y]=0;
    bool win=0;
    for(auto [dx,dy]:go)win|=!f(x+dx,y+dy);
    return dp[x][y]=win;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)go.push_back({i,i});
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
    int t;scanf("%d",&t);
    while(t--){
        int x,y;scanf("%d%d",&x,&y);
        printf(f(x,y)?"First\n":"Second\n");
    }
    return 0;
}