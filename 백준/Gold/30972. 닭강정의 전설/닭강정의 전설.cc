#include<bits/stdc++.h>
using namespace std;

int a[5001][5001];
int f(int r1,int c1,int r2,int c2){
    return a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1];
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int x;scanf("%d",&x);
        a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
    }
    int q;scanf("%d",&q);
    while(q--){
        int r1,c1,r2,c2;scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        printf("%d\n",f(r1+1,c1+1,r2-1,c2-1)*2-f(r1,c1,r2,c2));
    }
}