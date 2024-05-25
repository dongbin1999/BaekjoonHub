#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e;scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int ans=0;
    for(int i=a;i<b;i++){
        if(i<0)ans+=c;
        else if(i>0)ans+=e;
        else ans+=d+e;
    }
    printf("%d",ans);
}