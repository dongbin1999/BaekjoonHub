#include <bits/stdc++.h>
using namespace std;

int main(){
    int d,h,m;scanf("%d%d%d",&d,&h,&m);
    int ans=0;
    ans+=d-11;
    ans*=24;
    ans+=h-11;
    ans*=60;
    ans+=m-11;
    printf("%d",ans<0?-1:ans);
}