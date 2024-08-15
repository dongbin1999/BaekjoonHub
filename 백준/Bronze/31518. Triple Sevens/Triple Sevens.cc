#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans=0,n;scanf("%d",&n);
    for(int i=0;i<3;i++){
        bool ok=0;
        for(int j=0;j<n;j++){
            int x;scanf("%d",&x);
            ok|=x==7;
        }
        ans+=ok;
    }
    printf("%d",ans==3?777:0);
    return 0;
}