#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n,0);
    for(int i=0;i<n;i++)scanf("%d",&v[i]),v[i]++;
    v[0]--;
    for(int i=1;i<n;i++){
        int x=min(v[i-1],v[i]);
        v[i]-=x,v[i-1]-=x;
        if(!v[i])break;
    }
    bool ans=1;
    for(int i=0;i<n;i++)if(v[i]-(i==n-1)>0)ans=0;
    printf(ans?"YES\n":"NO\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}