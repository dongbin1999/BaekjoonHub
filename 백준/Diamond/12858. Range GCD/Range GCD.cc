#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
const int sz=1<<17;
ll _gcd[sz*2],diff[sz*2];//diff[i]=a[i+1]-a[i], a[0]=0

ll sum(int s,int e,int node,int ns,int ne){//sum(0,i-1)=a[i]
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return diff[node];
    int mid=(ns+ne)/2;
    return sum(s,e,node*2,ns,mid)+sum(s,e,node*2+1,mid+1,ne);
}ll sum(int s,int e){return sum(s,e,1,0,sz-1);}

void update(int i,ll val){//인덱스 i이상의 모든 원소에 val을 더함
    i+=sz,diff[i-1]+=val;
    int ii=i-1;
    while(ii>1)ii/=2,diff[ii]=diff[ii*2]+diff[ii*2+1];
    _gcd[i]=sum(0,i-sz-1);
    while(i>1)i/=2,_gcd[i]=GCD(_gcd[i*2],_gcd[i*2+1]);
    while(ii>1)ii/=2,diff[ii]=diff[ii*2]+diff[ii*2+1];
}

ll query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return _gcd[node];
    int mid=(ns+ne)/2;
    return GCD(query(s,e,node*2,ns,mid),query(s,e,node*2+1,mid+1,ne));
}ll query(int s,int e){return query(s,e,1,0,sz-1);}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll x;scanf("%lld",&x);
        update(i,x);update(i+1,-x);
    }
    int q;scanf("%d",&q);
    while(q--){
        ll x,a,b;scanf("%lld%lld%lld",&x,&a,&b);
        if(!x)printf("%lld\n",query(a,b));
        else update(a,x),update(b+1,-x);
    }
    return 0;
}