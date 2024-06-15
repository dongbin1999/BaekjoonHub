#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
typedef array<int,4> arr;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    priority_queue<arr> pq;
    map<int,vector<tup>> ma;
    map<int,int> color;
    int ylimit=1e9;
    while(n--){
        int x,y,p,c;scanf("%d%d%d%d",&x,&y,&p,&c);
        ma[x].push_back({y,p,c});
    }
    int ans=0,point=0;
    for(auto [x,v]:ma){
        for(auto [y,p,c]:v)
            if(ylimit>y)pq.push({y,x,p,c}),color[c]++,point+=p;
        while(!pq.empty()&&color.size()==k){
            auto [cy,cx,cp,cc]=pq.top();pq.pop();
            point-=cp,ylimit=min(ylimit,cy),color[cc]--;
            if(!color[cc])color.erase(cc);
        }
        while(!pq.empty()){
            auto [cy,cx,cp,cc]=pq.top();
            if(cy<ylimit)break;
            point-=cp,color[cc]--,pq.pop();
            if(!color[cc])color.erase(cc);
        }
        ans=max(ans,point);
    }
    printf("%d",ans);
}