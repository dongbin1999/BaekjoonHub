#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

vector<int> dag[300001],dag2[300001];
int in[300001],in2[300001];
ll ans[300001],ans2[300001];

int main() {
    int n,k,p;scanf("%d%d%d",&n,&k,&p);
    while(p--){
        int x,y;scanf("%d%d",&x,&y);
        in[x]++,dag[y].push_back(x);
        in2[y]++,dag2[x].push_back(y);
    }
    int num=n-k,num2=k-1;
    priority_queue<int,vector<int>,greater<int>> pq,pq2;
//    priority_queue<int> pq2;
    for(int i=0;i<k;i++){
        if(!in[i])pq.push(i);
        if(!in2[i])pq2.push(i);
    }
    while(!pq.empty()){
        int cur=pq.top();pq.pop();
        ans[cur]=num++;
        for(auto nx:dag[cur])
            if(--in[nx]==0)pq.push(nx);
    }
    while(!pq2.empty()){
        int cur=pq2.top();pq2.pop();
        ans2[cur]=num2--;
        for(auto nx:dag2[cur])
            if(--in2[nx]==0)pq2.push(nx);
    }
//    for(int i=k-1;i>=0;i--)printf("%lld ",ans[i]);
//    printf("\n");
//    for(int i=k-1;i>=0;i--)printf("%lld ",ans2[i]);
    ll x=0,d=1;
    for(int i=0;i<n;i++){
        x=(x+(ans[i]-ans2[i]+mod)%mod*d%mod)%mod;
        d=(d*n)%mod;
    }
    printf("%lld",x);
}