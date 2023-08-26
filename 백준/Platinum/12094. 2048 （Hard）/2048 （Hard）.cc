#include <bits/stdc++.h>
using namespace std;
int ans,n;
void go(int (*v)[20],int it){
    if(!it){
        for(int x=0;x<n;x++)for(int y=0;y<n;y++)ans=max(ans,v[x][y]);
        return;
    }
    int moved[20][20];
    memset(moved,0,sizeof(moved));

    bool equal=1;int mx=0;
    for(int x=0;x<n;x++){
        int prev=v[x][0],index=0;
        for(int y=1;y<n;y++){
            if(!v[x][y])continue;
            if(prev==v[x][y])
                moved[x][index++]=prev<<1,ans=max(ans,prev<<1),mx=max(mx,prev<<1),prev=0,equal=0;
            else{
                if(prev){
                    if(v[x][index]!=prev)equal=0;
                    moved[x][index++]=prev,mx=max(mx,prev);
                }
                prev=v[x][y];
            }
        }
        if(prev){
            if(v[x][index]!=prev)equal=0;
            moved[x][index]=prev,mx=max(mx,prev);
        }
    }
    if((ans>>(it-1))>=mx)return;

    for(int d=0;d<4;d++){
        if(equal&&!d)continue;
        if(d==0)for(int x=0;x<n;x++)for(int y=0;y<n;y++)v[x][y]=moved[x][y];
        else if(d==1)for(int x=0;x<n;x++)for(int y=0;y<n;y++)v[x][y]=moved[n-1-x][n-1-y];
        else if(d==2)for(int x=0;x<n;x++)for(int y=0;y<n;y++)v[x][y]=moved[y][x];
        else if(d==3)for(int x=0;x<n;x++)for(int y=0;y<n;y++)v[x][y]=moved[n-1-y][n-1-x];
        go(v,it-1);
    }
}

int main(){
    scanf("%d",&n);
    int v[20][20],nx[20][20];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&v[i][j]),ans=max(ans,v[i][j]);
    for(int d=0;d<4;d++){
        if(d==0)for(int x=0;x<n;x++)for(int y=0;y<n;y++)nx[x][y]=v[x][y];
        else if(d==1)for(int x=0;x<n;x++)for(int y=0;y<n;y++)nx[x][y]=v[n-1-x][n-1-y];
        else if(d==2)for(int x=0;x<n;x++)for(int y=0;y<n;y++)nx[x][y]=v[y][x];
        else if(d==3)for(int x=0;x<n;x++)for(int y=0;y<n;y++)nx[x][y]=v[n-1-y][n-1-x];
        go(nx,10);
    }
    printf("%d",ans);
    return 0;
}