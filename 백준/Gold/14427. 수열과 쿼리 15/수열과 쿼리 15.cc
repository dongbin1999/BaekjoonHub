#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n+1);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pq.push({a[i],i});
    }
    int m;scanf("%d",&m);
    while(m--){
        int q;scanf("%d",&q);
        if(q==1){
            int i,v;scanf("%d%d",&i,&v);
            a[i]=v;pq.push({v,i});
        }
        else{
            while(a[pq.top().second]!=pq.top().first)pq.pop();
            printf("%d\n",pq.top().second);
        }
    }
    return 0;
}