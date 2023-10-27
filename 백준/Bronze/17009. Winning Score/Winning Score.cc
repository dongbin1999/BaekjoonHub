#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=3,b=3,c=0,d=0;
    while(a--){
        int x;scanf("%d",&x);
        c+=x*(a+1);
    }
    while(b--){
        int x;scanf("%d",&x);
        d+=x*(b+1);
    }
    if(c>d)printf("A");
    else if(c<d)printf("B");
    else printf("T");
    return 0;
}