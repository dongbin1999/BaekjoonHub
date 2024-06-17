#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int x=(a+d)*100+d,y=(b+c)*100+b;
    if(x>y)printf("Persepolis");
    else if(x==y)printf("Penalty");
    else printf("Esteghlal");
    return 0;
}