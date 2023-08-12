#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
typedef long long ll;
const int sz=1<<17;
ll arr[sz<<1],lazy[sz<<1];

vector<int> tree[sz];
int in[sz],out[sz],dfsn;

void dfs(int node,int pa=-1){
    in[node]=++dfsn;
    for(auto nx:tree[node])
        if(nx!=pa)dfs(nx,node);
    out[node]=dfsn;
}

void propagate(int node,int ns,int ne){
    if(!lazy[node])return;
    if(node<sz){
        lazy[node<<1]+=lazy[node];
        lazy[node<<1|1]+=lazy[node];
    }
    arr[node]+=lazy[node]*(ll)(ne-ns+1);
    lazy[node]=0;
}

void update(int s,int e,ll k,int node,int ns,int ne){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[node]+=k;
        propagate(node,ns,ne);return;
    }
    int mid=(ns+ne)>>1;
    update(s,e,k,node<<1,ns,mid),update(s,e,k,node<<1|1,mid+1,ne);
    arr[node]=arr[node<<1]+arr[node<<1|1];
}void update(int s,int e,ll k){update(s,e,k,1,0,sz-1);}

ll query(int s,int e,int node,int ns,int ne){
    propagate(node,ns,ne);
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}ll query(int x){return query(x,x,1,0,sz-1);}

int main(){
    int n,k;ll j;scanf("%d%d%lld",&n,&k,&j);
    for(int i=2;i<=n;i++){
        int pa;scanf("%d",&pa);
        tree[pa].push_back(i);
        tree[i].push_back(pa);
    }
    dfs(1);
    map<int,vector<int>> song;
    vector<int> singer(n+1),comp;//singer : i번 곡을 부른 가수, comp : 중복 가수가 없도록 처리해준 것
    for(int i=1;i<=n;i++){
        scanf("%d",&singer[i]),song[singer[i]].push_back(in[i]);
        if(song[singer[i]].size()==1)comp.push_back(singer[i]);
    }
    vector<tup> v(k+1);
    for(int i=1;i<=k;i++){
        int t,p,s;scanf("%d%d%d",&t,&p,&s);
        v[i]={t,p,s/(out[p]-in[p]+1)};
    }
    sort(v.begin()+1,v.end());
    vector<pii> lr(comp.size(),{1,k});
    vector<int> ans(n+1,2e9);
    int cnt=ceil(log2(k))+1;//pbs 횟수
    while(cnt--){
        memset(arr,0,sizeof(arr));memset(lazy,0,sizeof(lazy));
        vector<tup> p;
        //comp[i](가수 번호)의 mid값을 담는다.
        for(int i=0;i<comp.size();i++)p.push_back({(lr[i].first+lr[i].second)/2,comp[i],i});
        sort(p.begin(),p.end());//mid가 작은 순으로 탐색.
        int qidx=1;
        for(auto [mid,_singer,i]:p){
            //mid까지 쿼리를 수행해준다.
            while(qidx<=mid){
                auto [t,p,s]=v[qidx++];
                update(in[p],out[p],s);
            }
            ll sum=0;
            for(auto x:song[_singer])sum+=query(x);
            if(sum>j*(ll)song[_singer].size())
                ans[_singer]=min(ans[_singer],mid),lr[i].second=mid-1;
            else lr[i].first=mid+1;
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[singer[i]]>1e9?-1:get<0>(v[ans[singer[i]]]));
    return 0;
}