#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int ans=-2e9;
    for(int i=0;i<1<<n;i++){
        vector<int> b;int x=i;
        while(x)b.push_back(x&1),x>>=1;
        b.erase(unique(b.begin(),b.end()),b.end());
        if(accumulate(b.begin(),b.end(),0)>m||__builtin_popcount(i)<m)continue;
        for(int j=0;j<n;j++)if(i>>j&1)x+=v[j];
        ans=max(ans,x);
    }
    printf("%d",ans);
}