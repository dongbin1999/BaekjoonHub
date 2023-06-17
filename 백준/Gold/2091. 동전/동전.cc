#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,a,b,c,d,y;scanf("%d%d%d%d%d",&x,&a,&b,&c,&d);
    int sum=a+b*5+c*10+d*25;
    x=sum-x;
    vector<int> ans={0,0,0,0,0};
    if(x<0)return !printf("0 0 0 0");
    for(int i=min(x/25,d);i>=0;i--){
        int xx=x-i*25,dd=d-i,cc=c,bb=b,aa=a;
        y=min(xx/10,c);xx-=y*10,cc-=y;
        y=min(xx/5,b);xx-=y*5,bb-=y;
        y=min(xx,a);xx-=y,aa-=y;
        if(!xx)ans=max(ans,{aa+bb+cc+dd,aa,bb,cc,dd});
    }
    return !printf("%d %d %d %d",ans[1],ans[2],ans[3],ans[4]);
}