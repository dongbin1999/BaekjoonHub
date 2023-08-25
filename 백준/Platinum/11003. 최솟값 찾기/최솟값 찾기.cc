#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> pq;
int a[5000001];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,l;cin>>n>>l;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
        while(pq.top().second<=i-l)pq.pop();
        cout<<pq.top().first<<' ';
    }
    return 0;
}