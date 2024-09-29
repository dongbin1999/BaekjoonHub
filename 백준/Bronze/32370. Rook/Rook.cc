#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,x,y;scanf("%d%d%d%d",&a,&b,&x,&y);
    if(!a&&!x&&abs(b)>abs(y)){
        printf("%d",3);
    }
    else if(!b&&!y&&abs(a)>abs(x)){
        printf("%d",3);
    }
    else if(!a||!b){
        printf("1");
    }
    else printf("2");
    return 0;
}