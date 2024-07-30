#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(k*(k+1)/2>n)return !printf("-1");
    if((n-k*(k+1)/2)%k)printf("%d",k);
    else printf("%d",k-1);
    return 0;
}