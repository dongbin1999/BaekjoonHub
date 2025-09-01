#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x);
    int x=0,ans=0;
    for(auto i:v){
        if(i==x)return !printf("-1");
        while(x+2<i)x+=2,ans++;
        if(x+1==i)x+=2,ans++;
        else x+=3,ans+=2;
    }
    printf("%d",ans);
}