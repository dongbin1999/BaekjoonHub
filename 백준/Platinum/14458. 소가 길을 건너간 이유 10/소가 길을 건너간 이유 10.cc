#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int sz=1<<17;
#define L 0
#define R 1
ll l[sz<<1],r[sz<<1];
ll lr[2][sz<<1],lazy[2][sz<<1];

void update(bool b,int i){
    i+=sz,(b?r:l)[i]++;
    while(i>1)i>>=1,(b?r:l)[i]=(b?r:l)[i<<1]+(b?r:l)[i<<1|1];
}

ll query(bool b,int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return (b?r:l)[node];
    int mid=(ns+ne)>>1;
    return query(b,s,e,node<<1,ns,mid)+query(b,s,e,node<<1|1,mid+1,ne);
}

void propagate(bool b,int node,int ns,int ne){
    if(!lazy[b][node])return;
    if(node<sz){
        lazy[b][node<<1]+=lazy[b][node];
        lazy[b][node<<1|1]+=lazy[b][node];
    }
    lr[b][node]+=lazy[b][node]*(ne-ns+1);
    lazy[b][node]=0;
}

void updateL(bool b,int s,int e,ll k,int node=1,int ns=0,int ne=sz-1){
    propagate(b,node,ns,ne);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[b][node]+=k;
        propagate(b,node,ns,ne);return;
    }
    int mid=(ns+ne)>>1;
    updateL(b,s,e,k,node<<1,ns,mid),updateL(b,s,e,k,node<<1|1,mid+1,ne);
    lr[b][node]=lr[b][node<<1]+lr[b][node<<1|1];
}void updateL(bool b,int i,ll k){updateL(b,i,i,k);}

ll queryL(bool b,int s,int e,int node=1,int ns=0,int ne=sz-1){
    propagate(b,node,ns,ne);
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return lr[b][node];
    int mid=(ns+ne)>>1;
    return queryL(b,s,e,node<<1,ns,mid)+queryL(b,s,e,node<<1|1,mid+1,ne);
}ll queryL(bool b,int i){return queryL(b,i,i);}


int main(){
    ll n;scanf("%lld",&n);
    map<ll,ll> ma;
    vector<ll> a(n),aa(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        ma[a[i]]=i;
    }
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&aa[i]);
        b[ma[aa[i]]]=i;
    }
//    for(auto [X,Y]:ma)printf("<%lld %lld> ",X,Y);
//    printf("\n");
//
//    for(int i=0;i<n;i++)printf("%lld ",b[i]);
//    printf("\n");
    ll ans=2e18;
    for(int i=0;i<n;i++){
        updateL(L,b[i],query(L,b[i],n));
        update(L,b[i]);
    }
    for(int i=n-1;i>=0;i--){
        updateL(R,b[i],query(R,0,b[i]));
        update(R,b[i]);
    }
    for(int i=0;i<n;i++){
        //for(int j=0;j<n;j++)printf("[%lld %lld] ",queryL(L,j),queryL(R,j));
        //printf("\n");
        ll cur=b[i];//printf("{%lld}\n",cur);
        ans=min(ans,queryL(L,0,n-1)+queryL(R,0,n-1));
        //printf("!%lld\n",queryL(L,0,n-1)+queryL(R,0,n-1));
        //assert(queryL(L,0,n-1)==queryL(R,0,n-1));
        //printf("<%lld %lld %lld>\n",cur,queryL(L,cur),queryL(R,cur));
        updateL(L,cur,n-1-queryL(L,cur)-queryL(R,cur));
        updateL(R,cur,-queryL(R,cur));
        updateL(R,cur+1,n-1,1);
        updateL(L,0,cur-1,-1);
    }
    memset(lr,0,sizeof(lr));memset(lazy,0,sizeof(lazy));
    memset(l,0,sizeof(l));memset(r,0,sizeof(r));

    swap(a,aa);

    ma.clear();
    for(int i=0;i<n;i++)ma[a[i]]=i;
    for(int i=0;i<n;i++)b[ma[aa[i]]]=i;

    for(int i=0;i<n;i++){
        updateL(L,b[i],query(L,b[i],n));
        update(L,b[i]);
    }
    for(int i=n-1;i>=0;i--){
        updateL(R,b[i],query(R,0,b[i]));
        update(R,b[i]);
    }
    for(int i=0;i<n;i++){
        ll cur=b[i];
        ans=min(ans,queryL(L,0,n-1)+queryL(R,0,n-1));
        updateL(L,cur,n-1-queryL(L,cur)-queryL(R,cur));
        updateL(R,cur,-queryL(R,cur));
        updateL(R,cur+1,n-1,1);
        updateL(L,0,cur-1,-1);
    }

    printf("%lld",ans/2);
    return 0;
}