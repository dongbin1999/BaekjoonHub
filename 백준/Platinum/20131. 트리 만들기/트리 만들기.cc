#include <bits/stdc++.h>
using namespace std;

int a[500001];

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n-2);
    priority_queue<int> pq;
    for(int i=0;i<n-2;i++)scanf("%d",&v[i]),a[v[i]]++;
    for(int i=1;i<=n;i++)if(!a[i])pq.push(i);
    vector<pair<int,int>> ans;
    for(auto x:v){
        if(pq.empty())break;
        int y=pq.top();pq.pop();
        ans.push_back({min(x,y),max(x,y)});
        a[x]--;
        if(!a[x])pq.push(x);
    }
    if(pq.size()!=2)return !printf("-1");
    int x=pq.top();pq.pop();
    int y=pq.top();
    ans.push_back({min(x,y),max(x,y)});
    sort(ans.begin(),ans.end());
    for(auto [x,y]:ans)printf("%d %d\n",x,y);
    return 0;
}