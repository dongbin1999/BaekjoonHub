#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int x;scanf("%d",&x);
    if(x>1)return !printf("NO");
    for(int i=1;i<n;i++){
        int y;scanf("%d",&y);
        if(!y)continue;
        if(x)x--,y--;
        if(y>1)return !printf("NO");
        x=y;
    }
    printf(x?"NO":"YES");
}