#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int m,n,w,h;scanf("%d%d%d%d",&m,&n,&w,&h);
    vector<pii> a(m+1);
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        a[i]={INT_MIN,x/w};
    }

    vector<int> d(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++)
        if(i+w-1>n){
            if(d[i])return !printf("-1");
        }
        else{
            if(d[i]<0)return !printf("-1");
            cnt[i]=d[i];
            for(int j=i;j<i+w;j++)d[j]-=cnt[i];
        }

    vector<vector<int>> ans(m+1);
    for(int i=1;i+w-1<=n;i++){
        priority_queue<pii> pq;
        for(int idx=1;idx<=m;idx++){
            auto [r,re]=a[idx];
            if(re&&r<=i)pq.push({re,idx});
        }
        if(pq.size()<cnt[i])return !printf("-1");
        unordered_set<int> se;
        while(cnt[i]--){
            auto [re,idx]=pq.top();pq.pop();
            se.insert(idx);
        }
        for(int idx=1;idx<=m;idx++)
            if(se.count(idx)){
                auto &[r,re]=a[idx];
                r=i+w+h,re--,ans[idx].push_back(i);
            }
    }
    printf("1\n");
    for(int i=1;i<=m;i++){
        for(auto j:ans[i])printf("%d ",j);
        printf("\n");
    }
}