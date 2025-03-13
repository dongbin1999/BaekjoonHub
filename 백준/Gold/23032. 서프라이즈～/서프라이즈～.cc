#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1),sum=v;
    for(int i=1;i<=n;i++)scanf("%d",&v[i]),sum[i]=v[i]+sum[i-1];
    array<int,2> ans={INT_MAX};
    for(int l=1;l<=n;l++){
        int s=v[l],h=v[l],idx=l;
        for(int r=l+1;r<=n;r++){
            s+=v[r];
            while(h+h<s)h+=v[++idx];
            ans=min(ans,{abs(h-(s-h)),-s});
            if(idx>l)h-=v[idx--],ans=min(ans,{abs(h-(s-h)),-s});
        }
    }
    printf("%d",-ans[1]);
}