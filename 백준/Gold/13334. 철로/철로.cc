#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii a,pii b){
    if(a.second==b.second)return a.first>b.first;
    return a.second<b.second;
}

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[x,y]:v){
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
    }
    int d;scanf("%d",&d);
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto [l,r]:v){
        pq.push(l);
        while(!pq.empty()&&pq.top()<r-d)pq.pop();
        cnt=max(cnt,(int)pq.size());
    }
    printf("%d",cnt);
}