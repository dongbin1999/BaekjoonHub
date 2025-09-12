#include<bits/stdc++.h>
using namespace std;
char a[101][101],b[101][101];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf(" %c",&a[i][j]);
    int x;scanf("%d",&x);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            if(x==1)b[i][j]=a[i][j];
            else if(x==3)b[n+1-i][j]=a[i][j];
            else b[i][n+1-j]=a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%c",b[i][j]);
        printf("\n");
    }
}