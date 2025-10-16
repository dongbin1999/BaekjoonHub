#include <cstdio>
int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int x=1,y=1,z=0;
    while(d--){
        z++;
        if(z>c)z-=c,y++;
        if(y>b)y-=b,x++;
    }
    printf("%d %d",x,y);
}