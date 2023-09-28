#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x;scanf("%d",&x);
        printf("%d is ",x);
        printf(abs(x)&1?"odd\n":"even\n");
    }
    return 0;
}