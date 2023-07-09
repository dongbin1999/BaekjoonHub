#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[200001],sum[200001],ans[200001];
vector<ll> v[200001];
int find(int a){
    if(u[a]<0)return a;
    return u[a]=find(u[a]);
}
ll merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return ans[a];
    if(v[a]<v[b])swap(a,b);
    ans[a]+=ans[b],u[a]+=u[b];
    while(!v[b].empty())
        ans[a]+=v[b].back()*sum[a],v[a].push_back(v[b].back()),v[b].pop_back();
    sum[a]+=sum[b],u[b]=a;
    return ans[a];
}
int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        ll x;scanf("%lld",&x);
        v[i].push_back(x),u[i]--,sum[i]=x;
    }
    while(q--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%lld\n",merge(a,b));
    }
}