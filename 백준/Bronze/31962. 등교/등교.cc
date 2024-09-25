#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;scanf("%d%d",&n,&x);
    int ans=-1;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        if(a+b<=x)ans=max(ans,a);
    }
    printf("%d",ans);
}