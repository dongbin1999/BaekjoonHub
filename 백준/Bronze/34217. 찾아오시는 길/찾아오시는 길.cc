#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a+c==b+d)printf("Either");
    else printf(a+c<b+d?"Hanyang Univ.":"Yongdap");
}