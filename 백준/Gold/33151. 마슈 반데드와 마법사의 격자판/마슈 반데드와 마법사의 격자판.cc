#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    int b=k/(n*n);k%=n*n;
    if(n%2==0&&k%2)return !printf("-1");
    int sum=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        a[i][j]=i+j+k&1,sum+=a[i][j];
    k-=sum;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            if(!a[i][j]&&k>0)a[i][j]+=2,k-=2;
            else if(a[i][j]&&k<0)a[i][j]-=2,k+=2;
            if(a[i][j]+b<0)return !printf("-1");
    }
    if(k)return !printf("-1");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%d ",a[i][j]+b);
        printf("\n");
    }
}