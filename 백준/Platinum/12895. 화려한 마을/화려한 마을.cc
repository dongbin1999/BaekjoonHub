#include <bits/stdc++.h>
using namespace std;
const int sz=1<<17;
int arr[sz*2],lazy[sz*2];

void propagate(int node,int ns,int ne){
    if(!lazy[node]) return;
    if(node<sz){
        lazy[node*2]=lazy[node];
        lazy[node*2+1]=lazy[node];
    }
    arr[node]=lazy[node];
    lazy[node]=0;
}

void update(int s,int e,int k,int node,int ns,int ne){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[node]=k;
        propagate(node,ns,ne); return;
    }
    int mid=(ns+ne)/2;
    update(s,e,k,node*2,ns,mid),update(s,e,k,node*2+1,mid+1,ne);
    arr[node]=arr[node*2]|arr[node*2+1];
}void update(int s,int e,int k){update(s,e,k,1,0,sz-1);}

int query(int s,int e,int node,int ns,int ne){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)|query(s,e,node*2+1,mid+1,ne);
}int query(int s,int e){return query(s,e,1,0,sz-1);}


int main(){
    int n,t,q;scanf("%d%d%d",&n,&t,&q);
    update(1,n,1);
    while(q--){
        char c;scanf(" %c",&c);
        if(c=='C'){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            if(x>y)swap(x,y);
            update(x,y,1<<(z-1));
        }
        else{
            int x,y;scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            printf("%d\n",__builtin_popcount(query(x,y)));
        }
    }
    return 0;
}