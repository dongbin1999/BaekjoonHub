#include <bits/stdc++.h>
using namespace std;
int ans[2000];
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        int mid=(a+180)%360;
        ans[mid+360-b]++,ans[mid+360+b+1]--;
    }
    for(int i=1;i<2000;i++)ans[i]+=ans[i-1];
    int x=0;
    for(int i=360;i<720;i++)x+=ans[i]||ans[i+360]||ans[i-360];
    printf("%d",x);
    return 0;
}