#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int x,y;cin>>x>>y;
        if(!x)break;
        printf("%d %d / %d\n",x/y,x%y,y);
    }
}