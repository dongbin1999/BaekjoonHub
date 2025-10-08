#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{-1,0},{0,-1},{1,0},{0,1}};
int a[102][102],state[4],goal[4];
char s[1000002],cmd[300];
int main() {
    int n,m;scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        scanf("%d",&a[i][j]);
        if(a[i][j]==2)x=i,y=j;
    }
    for(int i=0;i<4;i++){
        scanf("%s",s);
        if(s[0]=='D')goal[i]=2;
        else if(s[0]=='S')goal[i]=3;
        else goal[i]=1;
    }
    scanf("%s",s);
    cmd['W']=0,cmd['A']=1,cmd['S']=2,cmd['D']=3;
    for(int i=0;i<m;i++){
        for(int j=0;j<4;j++)state[j]>>=1;
        state[cmd[s[i]]]|=2;
        for(int j=0;j<4;j++){
            if(state[j]!=goal[j])continue;
            auto [dx,dy]=go[j];
            int nx=x+dx,ny=y+dy;
            if(nx<1||ny<1||nx>n||ny>n||a[nx][ny]==1)continue;
            x=nx,y=ny;
        }
    }
    printf("%d %d",x,y);
}