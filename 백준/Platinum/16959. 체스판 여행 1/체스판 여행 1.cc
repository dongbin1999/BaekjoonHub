#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;

int a[100][101][3],b[10][10];
vector<pii> knight={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
vector<pii> rook={{0,1},{0,-1},{1,0},{-1,0}};
vector<pii> bishop={{1,1},{1,-1},{-1,1},{-1,-1}};

int main(){
    memset(a,0x3f,sizeof(a));
    int n,init;scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        scanf("%d",&b[i][j]);
        if(b[i][j]==1)init=i*n+j;
    }
    a[init][1][0]=a[init][1][1]=a[init][1][2]=0;
    queue<tup> q;q.push({init,1,0}),q.push({init,1,1}),q.push({init,1,2});
    while(!q.empty()){
        auto [cur,num,piece]=q.front();q.pop();
        if(num==n*n)return !printf("%d",a[cur][num][piece]);
        int x=cur/n,y=cur%n;
        if(!piece){
            for(auto [dx,dy]:knight){
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                int ncur=nx*n+ny,nnum=b[nx][ny]==num+1?num+1:num;
                if(a[ncur][nnum][piece]>1e9)
                    a[ncur][nnum][piece]=a[cur][num][piece]+1,q.push({ncur,nnum,piece});
            }
        }
        else {
            for(auto [dx,dy]:piece==1?rook:bishop){
                int nx=x,ny=y;
                while(1){
                    nx+=dx,ny+=dy;
                    if(nx<0||nx>=n||ny<0||ny>=n)break;
                    int ncur=nx*n+ny,nnum=b[nx][ny]==num+1?num+1:num;
                    if(a[ncur][nnum][piece]>1e9)
                        a[ncur][nnum][piece]=a[cur][num][piece]+1,q.push({ncur,nnum,piece});
                }
            }
        }
        for(int i=1;i<=2;i++)
            if(a[cur][num][(piece+i)%3]>1e9)
                a[cur][num][(piece+i)%3]=a[cur][num][piece]+1,q.push({cur,num,(piece+i)%3});
    }
    return 0;
}