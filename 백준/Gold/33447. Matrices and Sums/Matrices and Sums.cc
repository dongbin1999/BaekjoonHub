#include <bits/stdc++.h>
using namespace std;
int a[2000][2000];

int main() {
    a[0][0]=1,a[0][1]=1,a[1][0]=0,a[1][1]=-1;
    int n;scanf("%d",&n);
    if(n%2)return !printf("No");
    printf("Yes\n");
    for(int i=0;i<n;i++)for(int j=0;j<=i;j++)a[i][j]=1,a[n-1-i][n-1-j]=-1;
    for(int i=0;i<n;i++)a[i][i]=i%2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}