#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
const int sz=1<<17;
int arr[sz<<1];

int query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 1e9;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return min(query(s,e,node<<1,ns,mid),query(s,e,node<<1|1,mid+1,ne));
}int query(int s,int e){return query(s,e,1,0,sz-1);}


vector<int> ans,pick;
bool update(int s,int e,int x,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e&&query(ns,ne)>=x)return 0;
    if(ns==ne){
        arr[node]=x;
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
    ans.assign(n,-1),pick.assign(n,0);
    map<int,vector<int>> ma;
//    vector<tup> check;
    while(q--){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
//        check.push_back({l,r,x});
        if(ma.find(x)==ma.end())ma[x]={l,r,l,r};
        else{
            vector<int> t=ma[x];
            t={max(t[0],l),min(t[1],r),min(t[2],l),max(t[3],r)};
            ma[x]=t;
        }
    }
    vector<vector<int>> v;
    for(auto [x,p]:ma){
        vector<int> t={x};
        for(auto i:p)t.push_back(i);
        v.push_back(t);

    }
    reverse(v.begin(),v.end());
    for(auto p:v){
        int x=p[0],nl=p[1],nr=p[2],wl=p[3],wr=p[4];
        if(!update(nl,nr,x)){while(n--)printf("-1 ");return 0;}
        update(wl,wr,x);
    }

//    printf("ans : ");
//    for(int i=0;i<n;i++)printf("%d ",ans[i]);
//    printf("\n");
//    printf("arr : ");
//    for(int i=0;i<n;i++)printf("%d ",query(i,i));
//    printf("\n");

    //min이 큰 순으로 빈칸 pq에 저장하기
    priority_queue<pii> pq;
    for(int i=0;i<n;i++)
        if(ans[i]<0)pq.push({query(i,i),i});

    for(int x=n-1;x>=0;x--){
        if(pick[x])continue;
        auto [mn,idx]=pq.top();pq.pop();
        if(mn>x){while(n--)printf("-1 ");return 0;}
        pick[x]=1,ans[idx]=x;
    }

//    for(auto [l,r,x]:check)
//        if(query(l,r)!=x){while(n--)printf("-1 ");return 0;}

    for(int i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}