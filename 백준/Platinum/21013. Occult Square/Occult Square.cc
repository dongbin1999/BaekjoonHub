#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main(){
    int n;scanf("%d",&n);
    if(n==2||n==3)return !printf("-1");
    if(n==5)return !printf("0 0 0 3 4\n"
                           "2 4 0 0 1\n"
                           "0 0 3 4 0\n"
                           "5 0 0 0 2\n"
                           "0 3 4 0 0");
    a[1][1]=n;
    for(int x=2,y=1+n/2;y<=n;x++,y+=n/2)
        for(int i=0;i<n/2;i++)a[x+i*2][y-i]=n;
    a[2][1+n/2]=a[3][n]=2,a[3][1+n/2]=a[2][n]=n-2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}