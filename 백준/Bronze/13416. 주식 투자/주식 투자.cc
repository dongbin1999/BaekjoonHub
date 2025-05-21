#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    int ans=0;
    while(n--){
       int x,y,z;scanf("%d%d%d",&x,&y,&z);
       ans+=max({0,x,y,z});
    }
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}