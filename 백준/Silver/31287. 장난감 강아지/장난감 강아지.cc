#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    string s;cin>>s;
    string a;
    int z=min(n,k);while(z--)a+=s;
    int x=0,y=0;
    for(auto i:a){
        if(i=='U')x--;if(i=='D')x++;
        if(i=='L')y--;if(i=='R')y++;
        if(!x&&!y)return !printf("YES");
    }
    printf("NO");
}