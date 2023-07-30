#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3];scanf("%d%d%d",&a[0],&a[1],&a[2]);
    if(a[0]==a[1]&&a[1]==a[2])return !printf("2");
    sort(a,a+3);
    if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])return !printf("1");
    printf("0");
    return 0;
}