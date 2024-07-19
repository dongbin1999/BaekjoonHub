#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int ans=1e9;
    for(int da=0;da<=c;da++){
        int sa=c-da;
        int ds=da*a+b*d,ss=sa*a;
        ans=min(ans,max(ds,ss));
    }
    printf("%d\n",ans);
}

int main() {
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}