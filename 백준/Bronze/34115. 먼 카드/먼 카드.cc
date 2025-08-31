#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1,1e9);n*=2;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        ans=max(ans,i-v[x]-1);
        v[x]=i;
    }
    printf("%d",ans);
    return 0;
}