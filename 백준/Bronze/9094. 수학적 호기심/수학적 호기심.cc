#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;scanf("%d",&n);
    while(n--){
        int n,m;scanf("%d%d",&n,&m);
        int ans=0;
        for(int i=1;i<n;i++)for(int j=i+1;j<n;j++)
            if((i*i+j*j+m)%(i*j)==0)ans++;
        printf("%d\n",ans);
    }
}