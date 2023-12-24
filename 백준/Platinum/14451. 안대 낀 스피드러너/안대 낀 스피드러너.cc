#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define in(x,y) (1<=x&&x<=n&&1<=y&&y<=n)
char s[100][100];
vector<pii> go={{0,1},{1,0},{0,-1},{-1,0}};//RDLU
bool vis[21][21][4][21][21][4];
struct info{int x1,y1,d1,x2,y2,d2,t;};

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    pii goal={1,n};
    queue<info> q;q.push({n,1,0,n,1,3,0}),vis[n][1][0][n][1][3]=1;
    while(!q.empty()){
        auto [x1,y1,d1,x2,y2,d2,t]=q.front();q.pop();
        if(pair{x1,y1}==goal&&pair{x2,y2}==goal)return !printf("%d",t);
        for(int i=0;i<2;i++){
            int ndir1=(d1+i*2+1)%4,ndir2=(d2+i*2+1)%4;
            if(vis[x1][y1][ndir1][x2][y2][ndir2])continue;
            vis[x1][y1][ndir1][x2][y2][ndir2]=1,q.push({x1,y1,ndir1,x2,y2,ndir2,t+1});
        }
        auto [dx1,dy1]=go[d1];auto [dx2,dy2]=go[d2];
        int nx1=x1+dx1,ny1=y1+dy1,nx2=x2+dx2,ny2=y2+dy2;
        if(pair{x1,y1}==goal||!in(nx1,ny1)||s[nx1][ny1]=='H')nx1=x1,ny1=y1;
        if(pair{x2,y2}==goal||!in(nx2,ny2)||s[nx2][ny2]=='H')nx2=x2,ny2=y2;
        if(vis[nx1][ny1][d1][nx2][ny2][d2])continue;
        vis[nx1][ny1][d1][nx2][ny2][d2]=1,q.push({nx1,ny1,d1,nx2,ny2,d2,t+1});
    }
    return 0;
}