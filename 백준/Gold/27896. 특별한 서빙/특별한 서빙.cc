#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int ans=0,cur=0;
    priority_queue<int> pq;
    for(auto i:v){
        cur+=i,pq.push(i);
        if(cur>=m)ans++,cur-=pq.top()*2,pq.pop();
    }
    printf("%d",ans);
}