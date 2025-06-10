#include<bits/stdc++.h>
using namespace std;

int query(int x){
    printf("%d\n",x);
    fflush(stdout);
    if(x==99)return 1e9;
    int r;scanf("%d",&r);
    return r;
}

int main(){
    int k=query(1);
    while(k<99){
        if(k%3)k=query(k/3*3+3);
        else k=query(k+2);
    }
    return 0;
}