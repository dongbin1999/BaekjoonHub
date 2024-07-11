#include<bits/stdc++.h>
using namespace std;

int main(){
    int e,l,b;scanf("%d%d%d",&e,&l,&b);
    vector<int> v(e+1);
    while(b--){
        int x;scanf("%d",&x);
        v[x]++;
    }
    int x=0,ans=0;
    while(x<e){
        int nx;
        for(int i=min(e,x+l);i>x;i--)
            if(!v[i]){nx=i;break;}
        ans++,x=nx;
    }
    printf("%d",ans);
    return 0;
}