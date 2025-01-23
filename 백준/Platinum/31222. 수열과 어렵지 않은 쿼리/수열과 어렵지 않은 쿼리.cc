#include<bits/stdc++.h>
using namespace std;
const int sz=1<<18;
int arr[sz<<1];

void update(int i,int val){
    i+=sz,arr[i]+=val;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}
int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}
int a[200001];

int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=a[i-1])update(i,1);
    }
    while(q--){
        int x,l,r;scanf("%d%d%d",&x,&l,&r);
        if(x==2)printf("%d\n",1+query(l+1,r));
        else{
            if(a[l]!=a[l-1])update(l,-1);
            if(a[l+1]!=a[l])update(l+1,-1);
            if(a[l-1]!=r)update(l,1);
            if(a[l+1]!=r)update(l+1,1);
            a[l]=r;
        }
    }
    return 0;
}