#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
char a[102][102];
bool vis[102][102];
int n,m;

bool ok(vector<pii> cl){
    char aa[102][102];memcpy(aa,a,sizeof(aa));
    for(auto [x,y]:cl){
        if(x==1||aa[x-1][y]=='x')return false;
        aa[x][y]='.',aa[x-1][y]='x';
    }
    return true;
}
void move(vector<pii> &cl){
    for(auto &[x,y]:cl)a[x][y]='.',a[x-1][y]='x',x--;
}

void f(int h,int d){
    if(d){for(int i=1;i<=m;i++)if(a[h][i]=='x'){a[h][i]='.';break;}}
    else {for(int i=m;i>=1;i--)if(a[h][i]=='x'){a[h][i]='.';break;}}
    memset(vis,0,sizeof(vis));
    vector<vector<pii>> clusters;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(vis[i][j]||a[i][j]!='x')continue;
        vector<pii> cl={{i,j}};
        queue<pii> q;q.push({i,j}),vis[i][j]=1;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||a[nx][ny]!='x')continue;
                q.push({nx,ny}),vis[nx][ny]=1,cl.push_back({nx,ny});
            }
        }
        sort(cl.begin(),cl.end());
        clusters.push_back(cl);
    }
    for(auto i:clusters)while(ok(i))move(i);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=n;i>=1;i--)scanf("%s",a[i]+1);
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x;scanf("%d",&x);
        f(x,i%2);
    }
    for(int i=n;i>=1;i--)printf("%s\n",a[i]+1);
}