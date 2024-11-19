#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> tup;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};

char s[1003][1003];
int d[1003][1003],vis[1003][1003];

int main(){
    int r,c;scanf("%d%d",&r,&c);
    pii start={-1,-1},end={-1,-1};
    for(int i=1;i<=r;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=c;j++)if(s[i][j]=='A'){
                if(start.first==-1)start={i,j};
                else end={i,j};
            }
    }
    int ans=1e9;
    for(auto [DX,DY]:go){
        int SX=start.first+DX,SY=start.second+DY;
        if(SX<1||SX>r||SY<1||SY>c||s[SX][SY]=='#')continue;
        if(pii{SX,SY}==end)return !printf("1");
        memset(d,0x3f,sizeof(d));d[start.first][start.second]=-1;
        deque<tup> dq;dq.push_front({SX,SY,1+(s[SX][SY]=='O')}),d[SX][SY]=1+(s[SX][SY]=='O');
        while(!dq.empty()){
            auto [x,y,dist]=dq.front();dq.pop_front();
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<1||nx>r||ny<1||ny>c||d[nx][ny]<1e9||s[nx][ny]=='#')continue;
                if(s[nx][ny]!='.')dq.push_back({nx,ny,dist+1}),d[nx][ny]=dist+1;
                else dq.push_front({nx,ny,dist}),d[nx][ny]=dist;
            }
        }
        int tmp=d[end.first][end.second];
        if(tmp>1e9)continue;
        if(tmp%2==0){ans=min(ans,tmp/2);continue;}
        int cnt=0;
        memset(vis,0,sizeof(vis));
        queue<pii> q;q.push({SX,SY}),vis[SX][SY]=1;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            if(s[x][y]!='.')cnt++;
            if(s[x][y]=='A')continue;
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<1||nx>r||ny<1||ny>c||vis[nx][ny]||s[nx][ny]=='#')continue;
                q.push({nx,ny}),vis[nx][ny]=1;
            }
        }
        if(cnt>tmp)ans=min(ans,tmp/2+1);
    }
    printf("%d",ans==1e9?-1:ans);
}