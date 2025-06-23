#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    if(n<3)return !printf("NO");
    printf("YES\n");
    while(n>=6){
        printf("2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n",
               n,n-2,n-1,n,n-2,n-1);
        n-=3;
    }
    if(n==5){
        printf("2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n",
               5,4,2,1,3,5,4,3,1,2);
    }
    if(n==4){
        printf("2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n",
               4,3,1,2,3,4,2,1);
    }
    if(n==3){
        printf("2 %d\n1 %d\n2 %d\n1 %d\n2 %d\n1 %d\n",
               n,n-2,n-1,n,n-2,n-1);
    }
}