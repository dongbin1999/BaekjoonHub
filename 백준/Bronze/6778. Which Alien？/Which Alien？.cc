#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    if(3<=a&&b<=4)printf("TroyMartian\n");
    if(a<=6&&2<=b)printf("VladSaturnian\n");
    if(a<=2&&b<=3)printf("GraemeMercurian\n");
    return 0;
}