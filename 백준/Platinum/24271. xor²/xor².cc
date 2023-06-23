#include <bits/stdc++.h>
using namespace std;
const int sz=1<<18;
int arr[sz*2];

void update(int i,int val){
    i+=sz,arr[i]^=val;
    while(i>1)i/=2,arr[i]=arr[i*2]^arr[i*2+1];
}

int query(int bit,int range,int x,int node,int lbit,int rbit){
    if(!range)return 0;
    if(bit==1)return (lbit^x)<(rbit^x)?arr[node*2]:arr[node*2+1];
    if((1<<(bit-1))>range)return (lbit^x)<(rbit^x)?query(bit-1,range,x,node*2,lbit,lbit+(1<<(bit-2))):
                    query(bit-1,range,x,node*2+1,rbit,rbit+(1<<(bit-2)));
    else return (lbit^x)<(rbit^x)?arr[node*2]^query(bit-1,range-(1<<(bit-1)),x,node*2+1,rbit,rbit+(1<<(bit-2))):
         query(bit-1,range-(1<<(bit-1)),x,node*2,lbit,lbit+(1<<(bit-2)))^arr[node*2+1];
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        update(i,x);
    }
    int q;scanf("%d",&q);
    while(q--){
        int c;scanf("%d",&c);
        if(c==1){
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(18,l,x,1,0,sz>>1)^query(18,r+1,x,1,0,sz>>1));
        }
        else{
            int i,x;scanf("%d%d",&i,&x);
            update(i,x);
        }
    }
    return 0;
}