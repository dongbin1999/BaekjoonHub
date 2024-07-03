#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> tup;
vector<int> comp;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
#define idx(x) (lower_bound(comp.begin(),comp.end(),x)-comp.begin())
pii ph[1000000];
int pic[1000000];

int main(){
    int n;scanf("%d",&n);
    vector<tup> v(n+2);int pre=0;
    for(int i=1;i<=n;i++){
        int h,w;scanf("%d%d",&w,&h);
        int l=pre+1,r=pre+w;
        v[i]={l,r,h};
        comp.push_back(l),comp.push_back(r);
        pre+=w;
    }
    int m;scanf("%d",&m);
    vector<tup> vv(n+2);pre=0;
    for(int i=1;i<=m;i++){
        int h,w;scanf("%d%d",&w,&h);
        int l=pre+1,r=pre+w;
        vv[i]={l,r,h};
        comp.push_back(l),comp.push_back(r);
        pre+=w;
    }
    UNIQUE(comp);
    for(int i=1;i<=n;i++){
        auto [l,r,h]=v[i];
        int il=idx(l),ir=idx(r);
        for(int j=il;j<=ir;j++)ph[j]={h,i};
    }
    vector<int> ans;
    priority_queue<pii> pq;
    for(int i=1;i<=m;i++){
        auto [l,r,h]=vv[i];
        auto [ll,lr,lh]=vv[i-1];auto[rl,rr,rh]=vv[i+1];
        if(lh<h&&rh<h){
            bool b=0;
            int il=idx(l),ir=idx(r);
            for(int j=il;j<=ir;j++)if(h==ph[j].first){
                b=1,ans.push_back({ph[j].second}),pq.push({h,j});
                break;
            }
            if(!b)return !printf("-1");
        }
    }
    while(!pq.empty()){
        auto [h,x]=pq.top();pq.pop();
        if(pic[x])continue;pic[x]=h;
        if(x-1>=0){
            int H=min(h,ph[x-1].first);
            pq.push({H,x-1});
        }
        if(x+1<comp.size()){
            int H=min(h,ph[x+1].first);
            pq.push({H,x+1});
        }
    }
    for(int i=1;i<=m;i++){
        auto [l,r,h]=vv[i];
        int il=idx(l),ir=idx(r);
        for(int j=il;j<=ir;j++)
            if(h!=pic[j])return !printf("-1");
    }
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}