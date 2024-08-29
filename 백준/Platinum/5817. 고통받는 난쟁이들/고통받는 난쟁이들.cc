#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int sz=1<<18;
pii arr[sz<<1];
int a[sz];

void update(int i,int x){
    i+=sz;arr[i]={x,x};
    while(i>1)i>>=1,arr[i]={min(arr[i<<1].first,arr[i<<1|1].first),max(arr[i<<1].second,arr[i<<1|1].second)};
}

pii query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return {1e9,-1e9};
    if(s<=ns&&ne<=e)return arr[node];
    int mid=ns+ne>>1;
    auto [lmn,lmx]=query(s,e,node<<1,ns,mid);
    auto [rmn,rmx]=query(s,e,node<<1|1,mid+1,ne);
    return {min(lmn,rmn),max(lmx,rmx)};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<sz<<1;i++)arr[i]={1e9,-1e9};
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),update(a[i],i);
    while(m--){
        int c,x,y;scanf("%d%d%d",&c,&x,&y);
        if(c==1){
            update(a[y],x),update(a[x],y),swap(a[x],a[y]);
        }
        else{
             auto [l,r]=query(x,y);
            printf(r-l==y-x?"YES\n":"NO\n");
        }
    }
}