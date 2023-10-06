#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int l=0,r=2e6,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        int g=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum>=mid)g++,sum=0;
        }
        if(g>=k)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}