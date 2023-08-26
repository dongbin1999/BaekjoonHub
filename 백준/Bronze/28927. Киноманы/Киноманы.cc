#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e,f;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int x=a*3+b*20+c*120,y=d*3+e*20+f*120;
    if(x>y)printf("Max");
    else if(x<y)printf("Mel");
    else printf("Draw");
    return 0;
}