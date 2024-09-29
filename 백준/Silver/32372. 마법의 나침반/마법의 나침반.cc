#include<bits/stdc++.h>
using namespace std;

int b[11][11];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int q=1;q<=m;q++){
        int x,y,k;scanf("%d%d%d",&x,&y,&k);
        if(k==1)while(x-1>=1)b[x-1][y]++,x--;
        if(k==5)while(x+1<=n)b[x+1][y]++,x++;
        if(k==3)while(y+1<=n)b[x][y+1]++,y++;
        if(k==7)while(y-1>=1)b[x][y-1]++,y--;
        if(k==2)for(int i=1;i<x;i++)for(int j=y+1;j<=n;j++)b[i][j]++;
        if(k==4)for(int i=x+1;i<=n;i++)for(int j=y+1;j<=n;j++)b[i][j]++;
        if(k==6)for(int i=x+1;i<=n;i++)for(int j=1;j<n;j++)b[i][j]++;
        if(k==8)for(int i=1;i<x;i++)for(int j=1;j<n;j++)b[i][j]++;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if(b[i][j]==m)return !printf("%d %d",i,j);
}