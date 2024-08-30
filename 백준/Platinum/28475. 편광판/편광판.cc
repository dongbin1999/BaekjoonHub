#include<bits/stdc++.h>
using namespace std;
const int sz=1<<18;
int arr[sz<<1],a[sz];

void update(int i,int val){
    i+=sz,arr[i]=val;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>1)update(i-1,abs(a[i-1]-a[i]+8)%8==2||abs(a[i-1]-a[i]+8)%8==6);
    }
    while(m--){
        int c,x,y;scanf("%d%d%d",&c,&x,&y);
        if(c==1){
            a[x]=y;
            if(x>1)update(x-1,abs(a[x-1]-a[x]+8)%8==2||abs(a[x-1]-a[x]+8)%8==6);
            if(x<n)update(x,abs(a[x+1]-a[x]+8)%8==2||abs(a[x+1]-a[x]+8)%8==6);
        }
        else{
            printf("%d\n",!query(x,y-1));
        }
    }
}