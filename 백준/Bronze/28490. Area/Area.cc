#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int mx=0;
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        mx=max(mx,x*y);
    }
    printf("%d",mx);
}