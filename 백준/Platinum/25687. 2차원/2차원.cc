#include <bits/stdc++.h>
using namespace std;

int a[2000][2000];

int main(){
    int n;scanf("%d",&n);
    int z=n*n;
    for(int i=0;i<n*n;i++){
        int v=i*(n+1)%(n*n);
        int x=v/n,y=v%n;
        a[x][y]=z--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}