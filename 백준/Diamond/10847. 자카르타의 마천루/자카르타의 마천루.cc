#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int b[30001],p[30001],d[30001];
unordered_set<int> idx[30001];

int main() {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&b[i],&p[i]);
        idx[b[i]].insert(p[i]);
    }

    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,b[0]});
    memset(d,0x3f,sizeof(d));
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<dist)continue;d[cur]=dist;
        if(cur==b[1])return !printf("%d",dist);
        vector<pii> del;
        for(auto P:idx[cur]){
            for(int npos=cur%P;npos<=n;npos+=P){
                int cost=abs(npos-cur)/P;
                for(auto np:idx[npos])if(np==P)del.push_back({np,npos});
                if(d[npos]>dist+cost)d[npos]=dist+cost,pq.push({dist+cost,npos});
            }
        }
        for(auto [x,y]:del)idx[y].erase(idx[y].find(x));
    }
    printf("-1");
}