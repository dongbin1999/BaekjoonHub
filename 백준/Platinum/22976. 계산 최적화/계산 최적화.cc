#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int sz=1<<19;
pll arr[sz*2];

pll cal(pll a,pll b){return {(a.first*b.second+b.first)%mod,a.second*b.second%mod};}
pll query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return {0,1};
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    pll l=query(s,e,node*2,ns,mid),r=query(s,e,node*2+1,mid+1,ne);
    return cal(l,r);
}
void update(int i,pll b){
    i+=sz;arr[i]=b;
    while(i>1)i/=2,arr[i]=cal(arr[i<<1],arr[i<<1|1]);
}


int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        char c;int x;scanf(" %c %d",&c,&x);
        pll p;if(c=='+')p={x,1};else p={0,x};
        update(i,p);
    }
    while(q--){
        int x,y;char c;scanf(" %d %c %d",&y,&c,&x);
        pll p;if(c=='+')p={x,1};else p={0,x};
        update(y,p);
        printf("%lld\n",query(1,n).first);
    }
}