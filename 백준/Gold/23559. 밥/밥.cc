#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;scanf("%d%d",&n,&x);
    x-=1000*n;
    int y=x/4000;
    priority_queue<array<int,3>> pq;
    for(int i=0;i<n;i++){
        int p,q;scanf("%d%d",&p,&q);
        pq.push({p-q,p,q});
    }
    int ans=0;
    while(n--){
        auto [mx,p,q]=pq.top();pq.pop();
        if(y&&p>q)y--,ans+=p;
        else ans+=q;
    }
    printf("%d",ans);
}