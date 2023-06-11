#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    if(b%a)return !printf("0");
    b/=a;
    int ans=0;
    for(int i=1;i*i<=b;i++)
        if(b%i==0){
            ans++;
            int x=b/i;
            if(x*x!=b)ans++;
        }
    printf("%d",ans);
    return 0;
}