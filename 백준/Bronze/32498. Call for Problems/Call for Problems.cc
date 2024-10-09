#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    while(n--){
        int x;scanf("%d",&x);
        ans+=x%2;
    }
    printf("%d",ans);
    return 0;
}