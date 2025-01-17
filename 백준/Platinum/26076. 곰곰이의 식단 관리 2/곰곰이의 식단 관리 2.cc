#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> arr;
pii go[8]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};

int a[2001][2001];
int b[2][2001][2001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    a[1][1]=a[n][m]=2;
    queue<arr> q;
    int ans=2;

    //위->왼 or 아래
    memset(b,0,sizeof(b));
    for(int i=1;i<=m;i++)if(a[1][i]==1)q.push({0,1,i}),b[0][1][i]=1;
        else if(a[1][i]!=2)q.push({1,1,i}),b[1][1][i]=1;
    while(!q.empty()){
        auto [c,x,y]=q.front();q.pop();
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]==2)continue;
            int nc=c+!a[nx][ny];
            if(nc>1||b[nc][nx][ny])continue;
            q.push({nc,nx,ny}),b[nc][nx][ny]=1;
        }
    }
    for(int i=1;i<=n;i++)if(b[0][i][1])ans=min(ans,0);
        else if(b[1][i][1])ans=min(ans,1);
    for(int i=1;i<=m;i++)if(b[0][n][i])ans=min(ans,0);
        else if(b[1][n][i])ans=min(ans,1);

    //오->왼 or 아래
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)if(a[i][m]==1)q.push({0,i,m}),b[0][i][m]=1;
        else if(a[i][m]!=2)q.push({1,i,m}),b[1][i][m]=1;
    while(!q.empty()){
        auto [c,x,y]=q.front();q.pop();
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]==2)continue;
            int nc=c+!a[nx][ny];
            if(nc>1||b[nc][nx][ny])continue;
            q.push({nc,nx,ny}),b[nc][nx][ny]=1;
        }
    }
    for(int i=1;i<=n;i++)if(b[0][i][1])ans=min(ans,0);
        else if(b[1][i][1])ans=min(ans,1);
    for(int i=1;i<=m;i++)if(b[0][n][i])ans=min(ans,0);
        else if(b[1][n][i])ans=min(ans,1);

    printf("%d",ans);
}