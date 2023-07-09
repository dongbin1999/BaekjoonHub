#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[200001],ans[200001];
int find(int a){
    if(u[a]<=0)return a;
    return u[a]=find(u[a]);
}
ll merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return ans[a];
    ans[a]+=u[a]*u[b]+ans[b],u[a]+=u[b],u[b]=a;
    return ans[a];
}
int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        ll x;scanf("%lld",&x);
        u[i]-=x;
    }
    while(q--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%lld\n",merge(a,b));
    }
}