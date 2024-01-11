#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1<<19;
ll arr[sz<<1],a[1000001];

void update(int i,ll val){
    i+=sz,arr[i]=val;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}

ll query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        a[x]=i;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        ll idx=a[x];
        ans+=query(idx+1,sz-1);
        update(idx,1);
    }
    printf("%lld",ans);
}