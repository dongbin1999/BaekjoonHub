#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;
pii go[4]={{0,1},{1,0},{0,-1},{-1,0}};

char a[100][101];
bool vis[100][100][10001];

int main(){
    int n,m,l;scanf("%d%d%d",&n,&m,&l);
    string s;cin>>s;
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    queue<tup> q;
    if(a[0][0]==s[0])q.push({0,0,1}),vis[0][0][0]=1;
    int ans=-1,ax,ay;
    while(!q.empty()){
        auto [x,y,len]=q.front();q.pop();
        if(len%l==0&&ans<len/l)ans=len/l,ax=x,ay=y;
        if(len>n*m)return !printf("-1");
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(nx<0||nx>=n||ny<0||ny>=m||a[nx][ny]!=s[len%l])continue;
            if(vis[nx][ny][len])continue;
            vis[nx][ny][len]=1,q.push({nx,ny,len+1});
        }
    }
    if(ans==-1)printf("-1");
    else printf("%d\n%d %d",ans,ax+1,ay+1);
}