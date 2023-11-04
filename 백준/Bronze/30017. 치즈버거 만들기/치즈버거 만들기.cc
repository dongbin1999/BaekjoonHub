#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    printf("%d",min(a,b+1)+min(a-1,b));
    return 0;
}