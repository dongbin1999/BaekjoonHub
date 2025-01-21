#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    map<int,priority_queue<pii>> ma;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        map<int,int> m;
        for(int j=2,k=v[i];j*j<=k;j++)
            while(v[i]%j==0)m[j]++,v[i]/=j;
        if(v[i]>1)m[v[i]]++;
        for(auto [a,b]:m)ma[a].push({b,i});
    }
    int m;scanf("%d",&m);
    for(auto [a,pq]:ma){
        printf("ENTER %d\n",a);
        while(!pq.empty()){
            vector<pii> x;int mm=m;
            printf("CLONE ");
            while(!pq.empty()&&mm--){
                auto [cnt,idx]=pq.top();pq.pop();
                x.push_back({cnt-1,idx});
                printf("%d ",idx+1);
            }
            printf("\n");
            for(auto [cnt,idx]:x)if(cnt)pq.push({cnt,idx});
        }
    }
    return 0;
}