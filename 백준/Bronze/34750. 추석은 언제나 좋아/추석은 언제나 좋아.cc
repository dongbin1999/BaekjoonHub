#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;scanf("%d",&a);
    int b=a/20,c=b;
    if(a>=100000)c+=b;
    if(a>=500000)c+=b;
    if(a>=1000000)c+=b;
    printf("%d %d",c,a-c);
}