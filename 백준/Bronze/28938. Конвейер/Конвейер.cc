#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int x=0,y;
    while(n--)scanf("%d",&y),x+=y;
    if(x<0)printf("Left");
    else if(x==0)printf("Stay");
    else printf("Right");
    return 0;
}