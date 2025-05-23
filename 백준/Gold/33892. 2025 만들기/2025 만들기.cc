#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    if(n<7)return !printf("NO");
    printf("YES\n");
    printf("7 * 6\n");printf("42 * 2\n");printf("84 - 3\n");printf("81 * 5\n");

    if(n>10){
        printf("11 - 10\n9 - 8\n1 - 1\n");
        for(int i=12;i<=n;i++)printf("%d * 0\n",i);
        printf("1 + 0\n");
    }
    else if(n>=9)printf("%d - %d\n1 * 1\n",n,n-1),n-=2;
    if(n==8)printf("8 - 4\n");
    printf("4 + 1\n");
    printf("405 * 5\n");
    return 0;
}