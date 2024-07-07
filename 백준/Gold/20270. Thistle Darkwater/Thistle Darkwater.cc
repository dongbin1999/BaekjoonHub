#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char s[500][500];
vector<pii> graph[500][500];
bool vis[500][500];

void solve(){
    int n;scanf("%d",&n);
    int sx=n-1,sy=sx*2;
    for(int i=0;i<n*2-1;i++){
        getchar();
        scanf("%[^\n]",s[i]);
    }
    for(int i=0;i<n*2-1;i++)for(int j=0;j<4*n-3;j++){
        if(abs(sx-i)+abs(sy-j)>(n-1)*2)continue;
        for(int dx=-1;dx<=1;dx++)for(int dy=-2;dy<=2;dy++){
            int nx=i+dx,ny=j+dy;
            if(abs(sx-nx)+abs(sy-ny)>(n-1)*2||nx<0||nx>=n*2-1)continue;
            if(abs(nx-i)+abs(ny-j)!=2)continue;
            graph[i][j].push_back({nx,ny});
        }
    }
    queue<pii> q;q.push({sx,sy}),vis[sx][sy]=1;
    set<pii> se;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(auto [nx,ny]:graph[x][y]){
            if(vis[nx][ny])continue;
            if(s[nx][ny]=='W')q.push({nx,ny}),vis[nx][ny]=1;
            else se.insert({nx,ny});
        }
    }
    int ans=0;
    for(auto [Sx,Sy]:se){
        if(vis[Sx][Sy])continue;
        int cnt=s[Sx][Sy]=='F';
        q.push({Sx,Sy}),vis[Sx][Sy]=1;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto [nx,ny]:graph[x][y]){
                if(vis[nx][ny]||s[nx][ny]=='W')continue;
                q.push({nx,ny}),vis[nx][ny]=1;
                cnt+=s[nx][ny]=='F';
            }
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    for(int i=0;i<n*2-1;i++)for(int j=0;j<4*n-3;j++)graph[i][j].clear(),vis[i][j]=0;
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}