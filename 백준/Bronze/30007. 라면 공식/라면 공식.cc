#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a,b,x;scanf("%d%d%d",&a,&b,&x);
        printf("%d\n",a*(x-1)+b);
    }
    return 0;
}