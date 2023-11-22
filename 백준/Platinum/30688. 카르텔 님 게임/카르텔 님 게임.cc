#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    int x=k+1,l=x+2,r=x+k;
    if(l<=n&&n<=r||n==k)printf("A and B win");
    else printf("C win");
}