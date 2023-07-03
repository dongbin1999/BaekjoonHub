#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,cnt=0;
    while(1){
        scanf("%d",&x);
        if(!x)break;
        printf("%d. ",++cnt);
        printf(x%2?"odd":"even");
        printf(" %d\n",x/2);
    }
    return 0;
}