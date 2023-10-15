#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int x=0,y=n%7==0;
    while(n)x|=n%10==7,n/=10;
    printf("%d",x*2+y);
}