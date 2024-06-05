#include<bits/stdc++.h>
using namespace std;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
typedef pair<int,int> pii;
typedef array<int,3> tup;

int main(){
    int n;scanf("%d",&n);
    vector<tup> v(n);
    vector<int> comp;
    map<int,vector<pii>> ma;
    for(auto &[l,h,r]:v){
        scanf("%d%d%d",&l,&h,&r);
        comp.push_back(l),comp.push_back(r);
        ma[l].push_back({h,r});
    }
    UNIQUE(comp);
    sort(v.begin(),v.end());
    priority_queue<pii> pq;
    vector<pii> ans={{0,0}};
    for(auto cur:comp){
        for(auto [h,r]:ma[cur])pq.push({h,r});
        while(!pq.empty()&&pq.top().second<=cur)pq.pop();
        int p=pq.empty()?0:pq.top().first;
        if(ans.back().second!=p)ans.push_back({cur,p});
    }
    for(int i=1;i<ans.size();i++)printf("%d %d ",ans[i].first,ans[i].second);
}