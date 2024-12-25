#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,h,n,a,b;scanf("%d%d%d%d%d",&w,&h,&n,&a,&b);
    if(w<a||h<b)return !printf("-1");
    int x=w/a*(h/b);
    printf("%d",(n+x-1)/x);
}