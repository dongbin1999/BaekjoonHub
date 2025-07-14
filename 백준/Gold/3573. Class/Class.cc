#include<bits/stdc++.h>
using namespace std;
int d[101][101];
int main(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    int x=1,y=1;
    d[x][y]++,a--;
    while(a){
        if(x==y&&x<b)d[++x][1]++,a--;
        else if(y<c)d[1][++y]++,a--;
        else if(x<b)d[++x][1]++,a--;
        else break;
    }
    while(x<b&&a)d[++x][y]++,a--;
    while(y<c&&a)d[x][++y]++,a--;
    for(int i=2;i<=b;i++)for(int j=2;j<=c;j++){
        if(!a)break;
        d[i][j]++,a--;
    }
    printf("%d\n",min(x,y));
    for(int i=1;i<=b;i++){
        for(int j=1;j<=c;j++)printf(d[i][j]?"#":".");
        printf("\n");
    }
}