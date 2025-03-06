#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=-1;
    for(int i=n+1;i<10000;i++){
        int x=i/100,y=i%100+x;
        if(y*y==i)return !printf("%d",i);
    }
    printf("-1");
}