#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,a=0,b=0;scanf("%d",&x);
    while(x--){
        char c;scanf(" %c",&c);
        c=='D'?a++:b++;
        if(abs(a-b)>1)return !printf("%d:%d",a,b);
    }
    printf("%d:%d",a,b);
}