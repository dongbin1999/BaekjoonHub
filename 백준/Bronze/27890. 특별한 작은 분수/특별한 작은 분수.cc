#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,n;scanf("%d%d",&x,&n);
    while(n--)x=x&1?x<<1^6:x>>1^6;
    printf("%d",x);
    return 0;
}