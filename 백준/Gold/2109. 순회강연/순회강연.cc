#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int main(){
    int n;scanf("%d",&n);
    if(!n)return !printf("0");
    priority_queue<int> pq;
    while(n--){
        int p,d;scanf("%d%d",&p,&d);
        v[d].push_back(p);
    }
    int ans=0;
    for(int i=10000;i>=1;i--){
        for(auto j:v[i])pq.push(j);
        if(!pq.empty())ans+=pq.top(),pq.pop();
    }
    printf("%d\n",ans);
    return 0;
}