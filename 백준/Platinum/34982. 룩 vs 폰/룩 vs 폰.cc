#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    if(n>=m)return !printf("1");
    if(n==1)return !printf("2");
    if(n==2&&k>3)return !printf("3");
    printf("%d",min(n+2,5));
}