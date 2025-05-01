#include<bits/stdc++.h>
using namespace std;

int a[1<<10][1<<10];

int main(){
    int n;scanf("%d",&n);
    if(n==1)return !printf("NO");
    printf("YES\n");
    int l=1,r=1<<n<<n;
    for(int i=0;i<1<<n;i++)for(int j=0;j<1<<n;j++){
        if(i+j&1)a[i][j]=r--;
        else a[i][j]=l++;
    }
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<1<<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}