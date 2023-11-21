#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int e=(1440+c*60+d-a*60-b)%1440;
    printf("%d %d",e,e/30);
}