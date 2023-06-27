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
    //구간의 and값이 이미 val의 1비트를 모두 갖고있으면, update하는게 의미 없으므로 종료.
    if(s<=ns&&ne<=e&&(_and[node]&val)==val)return;
    //바닥 끝까지 내려와서 모두 탐색해도, 업데이트는 총 30번까지만 일어나기 때문에 30n의 시간복잡도로 커버 가능.
    if(ns==ne){
        _and[node]|=val;
        //k가 아니었다가, k가 된 경우. 그 표시로 1<<31을 켜줌.
        if(_and[node]==k)update(ns,1),_and[node]^=1ll<<31;
        //원래 k였는데, 켜져서는 안되는 어떤 비트가 켜져서 k가 아니게 된 경우. 1<<31표시를 다시 꺼줌.
        else if((_and[node]&~k)&&(_and[node]>>31))update(ns,-1),_and[node]^=1ll<<31;
        return;
    }
    int mid=(ns+ne)/2;
    or_update(s,e,val,node*2,ns,mid),or_update(s,e,val,node*2+1,mid+1,ne);
    _and[node]=_and[node*2]&_and[node*2+1];
}void or_update(int s,int e,ll val){or_update(s,e,val,1,0,sz-1);}

int main(){
    int n;scanf("%d%lld",&n,&k);
    //k=0일때 예외처리.
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