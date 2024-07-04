#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;scanf("%d%d",&n,&k);
    int c=k,cnt=0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]==c)c--;
        else if(v[i]==k)c=k-1;
        else c=k;
        if(!c)cnt++,c=k;
    }
    printf("%d\n",cnt);
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case #%d: ",i);
        solve();
    }
}