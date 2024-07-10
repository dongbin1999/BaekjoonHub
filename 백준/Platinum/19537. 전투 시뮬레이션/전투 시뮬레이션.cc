#include<bits/stdc++.h>
using namespace std;
typedef array<int,4> arr;
typedef array<int,3> tup;
typedef pair<int,int> pii;
vector<pii> go={{0,1},{0,-1},{1,0},{-1,0}};
int s[502][502],r[100],ma[502][502],e[2][502][502],n,h,w;
bitset<502> vis[502];
vector<arr> unit(1);

void m(int u,int a,int b){
    auto &[M,T,X,Y]=unit[u];
    if(ma[a][b]!=-1||s[a][b]>M||(X==a&&Y==b))return;
    vector<queue<pii>> q(M+1);
    vector<pii> cl;
    q[M].push({X,Y});
    for(int m=M;m>=0;m--){
        while(!q[m].empty()){
            auto [x,y]=q[m].front();q[m].pop();
            if(vis[x][y])continue;vis[x][y]=1,cl.push_back({x,y});
            if(x==a&&y==b){
                for(auto &[dx,dy]:go)e[T][X+dx][Y+dy]--;
                swap(ma[X][Y],ma[a][b]);
                unit[u]={M,T,a,b};
                for(auto &[dx,dy]:go)e[T][a+dx][b+dy]++;
                for(auto &[xx,yy]:cl)vis[xx][yy]=0;
                return;
            }
            for(auto &[dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<1||nx>h||ny<1||ny>w)continue;
                if(s[nx][ny]>m)continue;
                if((ma[nx][ny]^T)==1)continue;
                if((nx!=a||ny!=b)&&e[!T][nx][ny])continue;
                q[m-s[nx][ny]].push({nx,ny});
            }
        }
    }
    for(auto &[xx,yy]:cl)vis[xx][yy]=0;
    return;
}

int main(){
    scanf("%d%d%d",&n,&h,&w);
    memset(s,0x3f,sizeof(s));
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)scanf("%d",&s[i][j]);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        if(r[i]==-1)r[i]=100;
    }
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)s[i][j]=r[s[i][j]];
    memset(ma,-1,sizeof(ma));
    int M;scanf("%d",&M);
    for(int i=1;i<=M;i++){
        int m,t,a,b;scanf("%d%d%d%d",&m,&t,&a,&b);a++,b++;
        unit.push_back({m,t,a,b});
        ma[a][b]=t;
        for(auto &[dx,dy]:go)e[t][a+dx][b+dy]++;
    }
    int k;scanf("%d",&k);
    while(k--){
        int u,a,b;scanf("%d%d%d",&u,&a,&b);
        m(u,a+1,b+1);
    }
    for(int i=1;i<=M;i++)printf("%d %d\n",unit[i][2]-1,unit[i][3]-1);
    return 0;
}