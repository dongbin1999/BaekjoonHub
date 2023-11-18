#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int x=sqrt(m);
    for(int i=0;i<x;i++)printf("1 "),n--,m--;
    if(x){
        printf("%d ",m%x),n--,m-=m%x;
        while(m>=x)printf("%d ",x),n--,m-=x;
    }
    assert(n>=0);
    while(n--)printf("0 ");
    return 0;
}