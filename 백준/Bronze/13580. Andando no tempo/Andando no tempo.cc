#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3];scanf("%d%d%d",&a[0],&a[1],&a[2]);
    for(int i=0;i<27;i++){
        if(i==13)continue;
        int x=0,y=i;
        for(int j=0;j<3;j++){
            if(y%3==0)x-=a[j];
            if(y%3==2)x+=a[j];
            y/=3;
        }
        if(!x)return !printf("S");
    }
    printf("N");
    return 0;
}