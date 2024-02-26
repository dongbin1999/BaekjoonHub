#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

pii go[4]={{0,1},{1,0},{0,-1},{-1,0}};
char s[1502][1502];
int d[1501][1501];
bool vis[1501][1501];

int main(){
    int r,c;scanf("%d%d",&r,&c);
    vector<pii> swan;
    queue<pii> q;
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
        for(int j=0;j<c;j++){
            if(s[i][j]=='L')swan.push_back({i,j});
            if(s[i][j]!='X')q.push({i,j}),d[i][j]=0;
        }
    }
    while(!q.empty()){
        auto[x,y]=q.front();q.pop();
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<0||nx>=r||ny<0||ny>=c||d[nx][ny]<1e9)continue;
            q.push({nx,ny}),d[nx][ny]=d[x][y]+(s[nx][ny]=='X');
        }
    }
    int L=0,R=max(r,c),mid,ans=R;
    while(L<=R){
        mid=(L+R)/2;
        memset(vis,0,sizeof(vis));
        q.push(swan[0]);vis[swan[0].first][swan[0].second]=1;
        bool ok=0;
        while(!q.empty()){
            auto[x,y]=q.front();q.pop();
            if(pii{x,y}==swan[1])ok=1;
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=r||ny<0||ny>=c||d[nx][ny]>mid||vis[nx][ny])continue;
                q.push({nx,ny}),vis[nx][ny]=1;
            }
        }
        if(ok)ans=min(ans,mid),R=mid-1;
        else L=mid+1;
    }
    printf("%d",ans);
    return 0;
}