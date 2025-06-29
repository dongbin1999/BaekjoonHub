#include<bits/stdc++.h>
using namespace std;

int a[2001][2001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i+=2){
        a[i][i]=i+1,a[i-1][i]=i;
        a[i-1][i-1]=a[i][i-1]=i-1;
    }
    if(n%2)a[n-1][n-1]=(n-1)*2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}