#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;
int u[100001];
int find(int x){
    if(u[x]<0)return x;
    else return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}
int main(){
    int n,q;scanf("%d%d",&n,&q);
    vector<tup> e(n);
    for(int i=1;i<n;i++){
        int x,y,r;scanf("%d%d%d",&x,&y,&r);
        e[i]={r,x,y};
    }
    sort(e.begin(),e.end(),greater<tup>());
    e.push_back({-1,-1,-1});
    memset(u,-1,sizeof(u));

    vector<tup> query(q);
    for(int i=0;i<q;i++){
        int k,v;scanf("%d%d",&k,&v);
        query[i]={k,v,i};
    }
    sort(query.begin(),query.end(),greater<tup>());
    vector<pii> ans;
    int idx=0;
    for(auto [k,v,i]:query){
        while(get<0>(e[idx])>=k){
            auto [r,x,y]=e[idx];
            merge(x,y);
            idx++;
        }
        ans.push_back({i,-u[find(v)]});
    }
    sort(ans.begin(),ans.end());
    for(auto [a,b]:ans)printf("%d\n",b-1);
}