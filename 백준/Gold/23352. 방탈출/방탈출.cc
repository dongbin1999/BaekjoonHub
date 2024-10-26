#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[51][51];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    pii ans={-1,0};
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(!a[i][j])continue;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pii> q;q.push({i,j}),vis[i][j]=0;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]>=0||!a[nx][ny])continue;
                vis[nx][ny]=vis[x][y]+1,q.push({nx,ny});
            }
        }
        int mx=0,val=0;
        for(int x=0;x<n;x++)for(int y=0;y<m;y++)mx=max(mx,vis[x][y]);
        for(int x=0;x<n;x++)for(int y=0;y<m;y++)if(vis[x][y]==mx)val=max(val,a[x][y]);
        ans=max(ans,{mx,val+a[i][j]});
    }
    printf("%d",ans.second);
}