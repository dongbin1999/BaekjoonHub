#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        int x,y;scanf("%d%d",&x,&y);
        x=min(x,y);
        printf("%d\n",x*(x+1)/2);
    }
}