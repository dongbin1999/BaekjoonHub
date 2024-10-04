#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;scanf("%d",&n);
    while(n--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",(b+b+c*a-c)*a/2);
    }
}