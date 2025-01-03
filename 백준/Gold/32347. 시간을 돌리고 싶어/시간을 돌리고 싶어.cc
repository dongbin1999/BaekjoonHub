#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> v(n+1);
    set<int> se;se.insert(1);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i])se.insert(i);
    }
    int l=1,r=n,mid,ans=n;
    while(l<=r){
        mid=(l+r)/2;
        int cur=n,K=0;
        while(cur>1){
            auto it=se.lower_bound(cur-mid);
            if(*it==cur){K=1e9;break;}
            cur=*it,K++;
        }
        if(K<=k)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
}