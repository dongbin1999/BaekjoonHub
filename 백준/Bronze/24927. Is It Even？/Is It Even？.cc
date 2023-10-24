#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    while(n--){
        int x;scanf("%d",&x);
        k-=__builtin_ctz(x);
    }
    printf("%d",k<=0);
    return 0;
}