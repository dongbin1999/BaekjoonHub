#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;vector<int> a(5);
    for(int i=0;i<5;i++)scanf("%d",&a[i]);
    scanf("%d",&k);
    int l=0,r=1e9,mid,ans=1e9;
    while(l<=r){
        mid=(l+r)/2;
        auto aa=a;long long kk=k;
        for(int i=0;i<5;i++)kk-=max(0,aa[i]-mid);
        if(kk>=0)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}