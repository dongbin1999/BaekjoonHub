#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> go[16];
pii dir[4]={{0,-1},{-1,0},{0,1},{1,0}};

int vis[50][50],wall[50][50];
pii color_and_size[50][50];

int main(){
    for(int i=0;i<16;i++)
        for(int j=0;j<4;j++)
            if(!(i>>j&1))go[i].push_back(dir[j]);
    int n,m;scanf("%d%d",&m,&n);
    int a=0,b=0,c=0,color=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&wall[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(vis[i][j])continue;
        vector<pii> group;
        int cnt=0;a++,color++;
        queue<pii> q;q.push({i,j}),vis[i][j]=1,cnt++,group.push_back({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto [dx,dy]:go[wall[x][y]]){
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny])continue;
                q.push({nx,ny}),vis[nx][ny]=1,cnt++,group.push_back({nx,ny});
            }
        }
        for(auto [x,y]:group)color_and_size[x][y]={color,cnt};
        b=max(b,cnt);
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        auto [co,sz]=color_and_size[i][j];
        for(auto [dx,dy]:go[0]){
            int nx=i+dx,ny=j+dy;
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            auto [nco,nsz]=color_and_size[nx][ny];
            if(co!=nco)c=max(c,sz+nsz);
        }
    }
    printf("%d\n%d\n%d",a,b,c);
}