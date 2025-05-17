#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(n<=k)return !printf("0");
    else printf("%d",n&k&1?n-1:n);
}