#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll mod=1000000007;

int u[1000002];
ll fib[1000001]={1,1},ans[1000001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    if(a<b)swap(a,b);
    u[a]+=u[b],u[b]=a;
    return true;
}

int main(){
    int n,q;scanf("%d%d",&n,&q);
    memset(u,-1,sizeof(u));
    vector<pii> v(q);
    for(int i=0;i<q;i++)scanf("%d%d",&v[i].first,&v[i].second);
    for(int i=2;i<=n;i++)fib[i]=(fib[i-2]+fib[i-1])%mod;
    reverse(v.begin(),v.end());
    for(auto [l,r]:v){
        int le=l-1;
        while(1){
            l=find(l);
            if(l>r||ans[l])break;
            ans[l]=fib[l-le];
            merge(l,find(l+1));
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}