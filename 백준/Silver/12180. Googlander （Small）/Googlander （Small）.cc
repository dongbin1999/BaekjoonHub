#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{-1,0},{0,1},{1,0},{0,-1}};
int ans,a[11][11],r,c;
void move(int x,int y,int d){
    a[x][y]=1;
    auto [dx,dy]=go[d];
    int nx=x+dx,ny=y+dy,nd=d,ok=0;
    if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&!a[nx][ny])
        move(nx,ny,nd),ok=1;
    auto [dx2,dy2]=go[(d+1)%4];
    nx=x+dx2,ny=y+dy2,nd=(d+1)%4;
    if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&!a[nx][ny])
        move(nx,ny,nd),ok=1;
    if(!ok)ans++;
    a[x][y]=0;
}
void solve(){
    scanf("%d%d",&r,&c);
    ans=0,move(r,1,0);
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
}