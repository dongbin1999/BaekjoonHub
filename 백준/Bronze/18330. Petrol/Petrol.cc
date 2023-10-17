#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    int x=min(b+60,a),y=a-x;
    printf("%d",x*1500+y*3000);
    return 0;
}