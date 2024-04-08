#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int sz=1<<17;
int arr[sz<<1];

void update(int i,int val){
    i+=sz,arr[i]=min(arr[i],val);
    while(i>1)i>>=1,arr[i]=min(arr[i<<1],arr[i<<1|1]);
}
int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 2e9;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return min(query(s,e,node<<1,ns,mid),query(s,e,node<<1|1,mid+1,ne));
}

int main(){
    memset(arr,0x3f,sizeof(arr));
    int n,k;scanf("%d%d",&n,&k);
    vector<pii> v(n+1);
    while(k--){
        int x,r,c;scanf("%d%d%d",&x,&r,&c);
        v[x]={r,c};
    }
    update(0,0);
    for(int x=1;x<=n;x++){
        auto [r,c]=v[x];
        update(x,query(x-1,x-1)+c);
        update(x+r,query(x-r-1,n)+c);
    }
    printf("%d",query(n,n));
    return 0;
}