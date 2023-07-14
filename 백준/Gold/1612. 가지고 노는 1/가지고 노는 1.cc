#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=1,d=1%n;
    while(ans<2e6&&d)
        ans++,d=(d*10+1)%n;
    printf("%d",ans==2e6?-1:ans);
    return 0;
}