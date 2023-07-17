#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
const int sz=1<<19;
int arr[sz*2],lazy[sz*2];

void propagate(int node,int ns,int ne){
    if(lazy[node]==-1) return;//할거없음
    if(node<sz){
        if(lazy[node]!=2){//lazy=and,or
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        else{//lazy=xor
            if(lazy[node*2]==-1)lazy[node*2]=2;
            else if(lazy[node*2]==2)lazy[node*2]=-1;
            else lazy[node*2]^=1;
            if(lazy[node*2+1]==-1)lazy[node*2+1]=2;
            else if(lazy[node*2+1]==2)lazy[node*2+1]=-1;
            else lazy[node*2+1]^=1;
        }
    }
    int len=ne-ns+1;
    if(lazy[node]!=2) arr[node]=lazy[node]*len;
    else arr[node]=len-arr[node];
    lazy[node]=-1;
}

void update(int s,int e,int node,int ns,int ne,int c){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e){
        lazy[node]=c;
        propagate(node,ns,ne); return;
    }
    int mid=(ns+ne)/2;
    update(s,e,node*2,ns,mid,c),update(s,e,node*2+1,mid+1,ne,c);
    arr[node]=arr[node*2]+arr[node*2+1];
}void update(int s,int e,int c){update(s,e,1,0,sz-1,c);}

int query(int s,int e,int node,int ns,int ne){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}int query(int s,int e){return query(s,e,1,0,sz-1);}

int main(){
    int n;scanf("%d",&n);
    memset(lazy,-1,sizeof(lazy));arr[sz]=1;
    vector<ll> comp={0,1};
    vector<tuple<ll,ll,ll>> v;
    for(int i=0;i<n;i++){
        ll q,l,r;scanf("%lld%lld%lld",&q,&l,&r);
        v.push_back({q,l,r});
        comp.push_back(l);
        comp.push_back(r);
        comp.push_back(l-1);
        comp.push_back(r+1);
    }
    UNIQUE(comp);
    for(auto [q,le,ri]:v){
        int lidx=lower_bound(comp.begin(),comp.end(),le)-comp.begin(),
        ridx=lower_bound(comp.begin(),comp.end(),ri)-comp.begin();
        if(q==3)q--;else q=2-q;
        update(lidx,ridx,q);
        int l=0,r=sz-1,mid,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(query(1,mid)==mid)ans=max(ans,mid),l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",comp[ans]+1);
    }
    return 0;
}