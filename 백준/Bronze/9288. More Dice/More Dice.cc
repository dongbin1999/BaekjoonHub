#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Case %d:\n",i);
        int x;scanf("%d",&x);
        for(int a=1;a<=6;a++){
            int b=x-a;
            if(a<=b&&b<=6)printf("(%d,%d)\n",a,b);
        }
    }
}