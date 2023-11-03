#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    while(a<=b){
        printf("All positions change in year %d\n",a);
        a+=60;
    }
    return 0;
}