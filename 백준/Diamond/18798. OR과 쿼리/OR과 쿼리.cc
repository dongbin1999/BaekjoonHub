#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1<<18;
int ok[sz*2];
ll _and[sz*2],k;

int sum(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return ok[node];
    int mid=(ns+ne)/2;
    return sum(s,e,node*2,ns,mid)+sum(s,e,node*2+1,mid+1,ne);
}int sum(int s,int e){return sum(s,e,1,0,sz-1);}

void update(int i,int val){
    i+=sz,ok[i]+=val;
    while(i>1)i/=2,ok[i]=ok[i*2]+ok[i*2+1];
}

void or_update(int s,int e,ll val,int node,int ns,int ne){
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e&&(_and[node]&val)==val)return;
    if(ns==ne){
        _and[node]|=val;
        if((_and[node]&~k)&&(_and[node]>>31))update(ns,-1),_and[node]^=1ll<<31;
        if(_and[node]==k)update(ns,1),_and[node]^=1ll<<31;
        return;
    }
    int mid=(ns+ne)/2;
    or_update(s,e,val,node*2,ns,mid),or_update(s,e,val,node*2+1,mid+1,ne);
    _and[node]=_and[node*2]&_and[node*2+1];
}void or_update(int s,int e,ll val){or_update(s,e,val,1,0,sz-1);}

int main(){
    int n;scanf("%d%lld",&n,&k);
    if(!k)for(int i=1;i<=n;i++)update(i,1),_and[i+sz]^=1ll<<31;
    for(int i=1;i<=n;i++){
        ll x;scanf("%lld",&x);
        or_update(i,i,x);
    }
    int q;scanf("%d",&q);
    while(q--){
        int c;scanf("%d",&c);
        if(c==1){
            int l,r;ll x;scanf("%d%d%lld",&l,&r,&x);
            or_update(l,r,x);
        }
        else{
            int l,r;scanf("%d%d",&l,&r);
            printf("%d\n",sum(l,r));
        }
    }
    return 0;
}