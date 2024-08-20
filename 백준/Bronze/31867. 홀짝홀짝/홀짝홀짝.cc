#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int o=0,e=0;
    while(n--){
        int x;scanf("%1d",&x);
        x%2?o++:e++;
    }
    if(o==e)printf("-1");
    else printf("%d",o>e);
}