#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;scanf("%d%d",&a,&b);
    if(a==1) printf("%d\n",1);
    else if(b==1) printf("%d\n",a==2?4:a+b);
    else printf("%d\n",a<=b?a+a:a);
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("#%d ",i);
        solve();
    }
    return 0;
}