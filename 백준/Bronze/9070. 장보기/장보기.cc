#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    pair<double,int> ans={2e9,0};
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        ans=min(ans,{-(double)x/y,y});
    }
    printf("%d\n",ans.second);
}

int main() {
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}