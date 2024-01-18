#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> lr={-1,1};
pii a[1001][1001];
int b[1001][1001],top[1001][1001];

int tx(pii p){
    auto [x,y]=p;
    if(top[x][y]!=-1)return top[x][y];
    if(x==1||b[x-1][y]==1)return top[x][y]=x;
    else return top[x][y]=tx({x-1,y});
}

int main(){
    memset(a,-1,sizeof(a));
    memset(top,-1,sizeof(top));
    int n,m,l,r;scanf("%d%d%d%d",&n,&m,&l,&r);
    pii init;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            scanf("%1d",&b[i][j]);
            if(b[i][j]==2)init={i,j};
        }
    init.first=tx(init);
    queue<pii> q; q.push(init);
    a[init.first][init.second]={l,r};
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        init=a[x][y];
        while(1){
            if(x>n||b[x][y]==1)break;
            a[x][y]=init;
            for(auto dy:lr){
                int ny=y+dy;
                auto [l,r]=a[x][y];
                dy<0?l--:r--;
                if(ny<=0||ny>m||b[x][ny]==1||l<0||r<0||a[tx({x,ny})][ny].first!=-1)continue;
                a[tx({x,ny})][ny]={l,r},q.push({tx({x,ny}),ny});
            }
            x++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=a[i][j].first!=-1;
    printf("%d",ans);
    return 0;
}