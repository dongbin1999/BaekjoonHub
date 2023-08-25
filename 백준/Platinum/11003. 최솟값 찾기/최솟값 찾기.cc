#include <bits/stdc++.h>
using namespace std;
struct p{int a,b;};
struct cmp{
    bool operator()(const p& a,const p& b){
        return a.a>b.a;
    }
};
priority_queue<p,vector<p>,cmp> pq;
int a[5000001];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,l;cin>>n>>l;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
        while(pq.top().b<=i-l)pq.pop();
        cout<<pq.top().a<<' ';
    }
    return 0;
}