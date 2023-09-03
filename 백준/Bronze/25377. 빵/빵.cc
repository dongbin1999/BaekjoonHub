#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=1e9;
    scanf("%d",&n);
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        if(a<=b)ans=min(ans,b);
    }
    printf("%d",ans==1e9?-1:ans);
    return 0;
}