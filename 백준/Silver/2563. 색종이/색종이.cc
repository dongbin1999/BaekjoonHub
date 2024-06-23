#include<bits/stdc++.h>
using namespace std;
int a[101][101];

int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        for(int i=x;i<x+10;i++)for(int j=y;j<y+10;j++)a[i][j]=1;
    }
    int ans=0;
    for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)ans+=a[i][j];
    printf("%d",ans);
    return 0;
}