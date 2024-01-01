#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void solve(){
    int n,l,k;scanf("%d%d%d",&n,&l,&k);
    vector<pii> v;
    deque<int> dq;
    while(n--){
        int id,x;scanf("%d%d",&x,&id);
        v.push_back({id>0?l-x:x,id});
        dq.push_back(id);
    }
    sort(v.begin(),v.end());
    vector<pii> vv;
    for(auto [len,id]:v){
        if(id<0)vv.push_back({len,dq.front()}),dq.pop_front();
        else vv.push_back({len,dq.back()}),dq.pop_back();
    }
    sort(vv.begin(),vv.end());
    printf("%d\n",vv[k-1].second);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}