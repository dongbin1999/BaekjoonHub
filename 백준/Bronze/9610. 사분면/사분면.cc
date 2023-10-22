#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int a[5]={0};
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        if(!(x*y))a[4]++;
        else if(x>0&&y>0)a[0]++;
        else if(x<0&&y>0)a[1]++;
        else if(x<0&&y<0)a[2]++;
        else if(x>0&&y<0)a[3]++;
    }
    for(int i=0;i<4;i++)printf("Q%d: %d\n",i+1,a[i]);
    printf("AXIS: %d",a[4]);
    return 0;
}