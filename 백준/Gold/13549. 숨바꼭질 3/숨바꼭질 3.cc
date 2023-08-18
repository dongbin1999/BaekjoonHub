#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> d(100001,1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,n});
    while(!pq.empty()){
        auto [dist,cur]=pq.top();pq.pop();
        if(d[cur]<1e9)continue;
        d[cur]=dist;
        if(cur<=5e4)pq.push({dist,cur<<1});
        if(cur>0)pq.push({dist+1,cur-1});
        if(cur<1e5)pq.push({dist+1,cur+1});
    }
    printf("%d",d[k]);
    return 0;
}