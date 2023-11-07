#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d ",i);
        if(i%6==0)printf("Go! ");
    }
    if(n%6)printf("Go! ");
    return 0;
}