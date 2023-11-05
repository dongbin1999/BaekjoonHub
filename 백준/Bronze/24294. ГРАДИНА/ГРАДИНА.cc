#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d",(a+b+c+d-min(a,c)+2)*2);
    return 0;
}