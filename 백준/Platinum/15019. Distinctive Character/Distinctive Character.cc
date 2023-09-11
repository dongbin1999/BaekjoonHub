#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,k;cin>>n>>k;
    vector<int> v,dist(1<<k,1e9);
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(stoi(s,0,2));
    }
    queue<pii> q;
    for(auto i:v)q.push({i,0}),dist[i]=0;
    while(!q.empty()){
        auto [num,d]=q.front();q.pop();
        for(int i=0;i<k;i++){
            int nx=num^(1<<i);
            if(dist[nx]<1e9)continue;
            dist[nx]=d+1,q.push({nx,d+1});
        }
    }
    pii ans={-1,-1};
    for(int i=0;i<1<<k;i++)ans=max(ans,{dist[i],i});
    while(k--)printf("%d",ans.second>>k&1);
    return 0;
}