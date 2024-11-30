#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    priority_queue<arr,vector<arr>,greater<arr>> pq;pq.push({0,1,k});
    for(int i=2;i<=n;i++){
        auto [d,x,r]=pq.top();pq.pop();
        printf("%d %d\n",x,i);
        pq.push({d+1,i,k-1});
        if(r>1)pq.push({d,x,r-1});
    }
}