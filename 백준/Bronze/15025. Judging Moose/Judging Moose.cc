#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r;scanf("%d%d",&l,&r);
    if(!l&&!r)return !printf("Not a moose");
    if(l!=r)printf("Odd %d",max(l,r)*2);
    else printf("Even %d",r*2);
    return 0;
}