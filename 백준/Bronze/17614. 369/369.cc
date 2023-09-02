#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        bool t=0;
        int ii=i;
        while(ii)t|=ii%10%3==0&&ii%10!=0,ii/=10;
        ans+=t;
    }
    printf("%d",ans);
    return 0;
}