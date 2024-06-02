#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> reqs;
int k,ans;
void go(vector<int> &v,int n){
    if(v.size()==k){
        int w=0;
        priority_queue<int,vector<int>,greater<int>> pq[6];
        for(int i=0;i<k;i++)for(int j=0;j<v[i];j++)pq[i+1].push(0);
        for(auto x:reqs){
            int a=x[0],b=x[1],c=x[2];
            auto p=pq[c].top();pq[c].pop();
            w+=max(0,p-a);
            pq[c].push(max(a,p)+b);
        }
        ans=min(ans,w);
        return;
    }
    for(int i=1;i<=n;i++){
        v.push_back(i);
        go(v,n-i);
        v.pop_back();
    }
}


int solution(int kk, int n, vector<vector<int>> r) {
    reqs=r,k=kk,ans=2e9;
    vector<int> v;
    go(v,n);
    return ans;
}