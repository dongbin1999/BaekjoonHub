#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x,y;scanf("%d%d",&x,&y);
        int ans=min(x-1,2)*y;
        ans+=max(0,x-3);
        printf("%d\n",ans);
    }
}