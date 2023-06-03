#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    bool mi=true;
    int x=v[0],len=1;
    for(int i=1;i<n;i++){
        if(mi){
            if(v[i]<x)len++,mi=!mi,x=v[i];
            else x=max(v[i],x);
        }
        else{
            if(v[i]>x)len++,mi=!mi,x=v[i];
            else x=min(v[i],x);
        }
    }
    printf("%d\n",len);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}