#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    if(n<4)return !printf("1 1 1 1");
    int x=(n+1)/3,y=0,nn=n,two=0;
    for(int i=2;i<=1000000;i++)while(n%i==0)y++,n/=i,two+=i==2;
    if(nn%3==1)printf("%d %d ",x+1,x);
    else printf("%d %d ",x,x);
    printf("%d %d",y,y-two/2);
}