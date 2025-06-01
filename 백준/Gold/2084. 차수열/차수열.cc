#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[2001][2001];
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    priority_queue<pii> pq;

    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i])pq.push({v[i],i});
    }
    while(!pq.empty()){
        auto [c1,p1]=pq.top();pq.pop();
        vector<pii> tmp;
        while(c1){
            if(pq.empty())return !printf("-1");
            auto [c2,p2]=pq.top();pq.pop();
            a[p1][p2]=a[p2][p1]=1,c1--,c2--;
            if(c2)tmp.push_back({c2,p2});
        }
        for(auto [x,y]:tmp)pq.push({x,y});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}