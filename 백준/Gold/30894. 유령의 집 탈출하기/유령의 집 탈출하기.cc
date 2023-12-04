#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> info;
#define ghost(x) ('0'<=x && x<='3')
#define in(x,y) (1<=x&&x<=n&&1<=y&&y<=m)
pii go[5]={{0,1},{1,0},{0,-1},{-1,0},{0,0}};
char init[502][502];
char h[502][502][4];
int vis[502][502][4];
 
int main(){
    int n,m,sx,sy,ex,ey;scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&ex,&ey);
    for(int i=1;i<=n;i++)scanf("%s",init[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(!ghost(init[i][j]))continue;
        for(int t=0;t<4;t++){
            int x=i,y=j;
            auto [dx,dy]=go[(init[i][j]-'0'+t)%4];
            while(1){
                x+=dx,y+=dy;
                if(!in(x,y)||ghost(init[x][y])||init[x][y]=='#')break;
                h[x][y][t]='#';
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int t=0;t<4;t++)
        if(!h[i][j][t])h[i][j][t]=init[i][j];
 
    queue<info> q; q.push({{sx,sy},{0,0}});
    while(!q.empty()){
        auto [cur,p]=q.front();q.pop();
        auto [x,y]=cur; auto [time,dist]=p;
        if(x==ex&&y==ey){
            printf("%d",dist);
            return 0;
        }
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy,nt=(time+1)%4;
            if(!in(nx,ny)||vis[nx][ny][nt]||h[nx][ny][nt]=='#'||ghost(h[nx][ny][nt]))continue;
            q.push({{nx,ny},{nt,dist+1}}),vis[nx][ny][nt]=1;
        }
    }
    printf("GG");
    return 0;
}