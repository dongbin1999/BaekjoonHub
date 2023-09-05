#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
struct s{int cost,x,y,idx;};
struct cmp{bool operator()(s a,s b){return a.cost>b.cost;}};
bool operator<(s a,s b){return a.cost>b.cost;}

pii go[]={{0,1},{0,-1},{1,0},{-1,0}};
map<pii,char> dir;
int dp[50][50][51];
char a[50][51],cmd[51];
int main(){
    memset(dp,0x3f,sizeof(dp));
    dir[{0,1}]='R',dir[{0,-1}]='L',dir[{1,0}]='D',dir[{-1,0}]='U';
    int n,m;scanf("%d%d",&n,&m);
    pii S,G;
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
        for(int j=0;j<m;j++)
            if(a[i][j]=='S')S={i,j};
            else if(a[i][j]=='G')G={i,j};
    }
    scanf("%s",cmd);int k=strlen(cmd);
    priority_queue<s,vector<s>,cmp> pq;
    pq.push({0,S.x,S.y,0});
    while(!pq.empty()){
        auto [c,x,y,i]=pq.top();pq.pop();
        if(dp[x][y][i]<1e9)continue;
        if(pii{x,y}==G)return !printf("%d",c);
        dp[x][y][i]=c;
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<0||nx>=n||ny<0||ny>=m||a[nx][ny]=='#')nx=x,ny=y;
            if(i<k&&dir[{dx,dy}]==cmd[i])pq.push({c,nx,ny,i+1});//커맨드 사용
            pq.push({c+1,nx,ny,i});//add
        }
        if(i<k)pq.push({c+1,x,y,i+1});//delete
    }
    return 0;
}