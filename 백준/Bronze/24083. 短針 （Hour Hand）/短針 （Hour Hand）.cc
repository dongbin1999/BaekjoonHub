#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    printf("%d",(a+b)%12?(a+b)%12:12);
    return 0;
}