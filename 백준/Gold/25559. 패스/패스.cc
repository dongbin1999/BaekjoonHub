#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    if(n==1) return !printf("1");
    if(n%2)return !printf("-1");
    for(int i=0;i<n;i+=2)printf("%d %d ",n-i,i+1);
    return 0;
}