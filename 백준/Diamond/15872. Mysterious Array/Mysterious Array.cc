#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll mod=1000000007;
const int sz=1<<18;
int arr[sz<<1];

int query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 1e9;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return min(query(s,e,node<<1,ns,mid),query(s,e,node<<1|1,mid+1,ne));
}int query(int s,int e){return query(s,e,1,0,sz-1);}

vector<int> ans,pick; ll ok;
bool update(int s,int e,int x,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e&&query(ns,ne)>=x)return 0;
    if(ns==ne){
        arr[node]=x,ok++;
        if(!pick[x])pick[x]=1,ans[ns]=x;
        while(node>1)node>>=1,arr[node]=min(arr[node<<1],arr[node<<1|1]);
        return 1;
    }
    int mid=(ns+ne)>>1;
    return update(s,e,x,node<<1,ns,mid)|update(s,e,x,node<<1|1,mid+1,ne);
}bool update(int s,int e,int x){return update(s,e,x,1,0,sz-1);}

int main(){
    memset(arr,-1,sizeof(arr));
    int n,q;scanf("%d%d",&n,&q);
    ans.assign(n+1,-1),pick.assign(n+1,0);
    map<int,vector<int>> ma;
    while(q--){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);x*=-1;
        if(ma.find(x)==ma.end())ma[x]={l,r,l,r};
        else{
            vector<int> t=ma[x];
            t={max(t[0],l),min(t[1],r),min(t[2],l),max(t[3],r)};
            ma[x]=t;
        }
    }

    ll answer=1;
    for(auto [mix,p]:ma){
        int x=-mix,nl=p[0],nr=p[1],wl=p[2],wr=p[3];
        ok=0;
        if(!update(nl,nr,x))return !printf("0");
        answer=(answer*ok)%mod;
        update(wl,wr,x);
    }

    vector<pii> v;
    for(int i=1;i<=n;i++)
        if(ans[i]<0)v.push_back({query(i,i),i});
    sort(v.begin(),v.end());
    ok=0;int idx=0;
    for(int x=1;x<=n;x++){
        if(pick[x])continue;
        while(idx<v.size()&&v[idx].first<=x)idx++,ok++;
        answer=(answer*ok)%mod;ok--;
    }
    printf("%lld",answer);
    return 0;
}