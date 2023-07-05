#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e;scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if(d==e){
        int hs=d,he=d+c;
        if(hs%(a+b)<=a||(he-1+a+b)/(a+b)>(hs-1+a+b)/(a+b))printf("0.0");
        else printf("1.0");
        return 0;
    }
    int can=0;
    for(int i=d;i<e;i++){
        int hs=i,he=i+c;
        if(hs%(a+b)<a||he/(a+b)>hs/(a+b))can++;
    }
    printf("%.12lf",1.0-(double)can/(double)(e-d));
}