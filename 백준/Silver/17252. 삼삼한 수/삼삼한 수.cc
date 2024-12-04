#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    if(!n)return !printf("NO");
    while(n)if(n%3==2)return !printf("NO");
    else n/=3;
    printf("YES");
}