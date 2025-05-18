#include<bits/stdc++.h>
using namespace std;

int query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<n*m;i+=2){
        int x=i/m+1,y=i%m+1;
        if(x%2==0&&m%2==0)y--;
        if(query(x,y))break;
    }
}