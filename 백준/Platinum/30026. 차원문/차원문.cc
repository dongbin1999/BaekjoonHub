#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int u[200001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}
int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        v[x]=i,merge(x,i);
    }
    vector<pii> ans;
    for(int i=1;i<n;i++)
        if(merge(v[i],v[i+1]))ans.push_back({v[i],v[i+1]}),swap(v[i],v[i+1]);
    printf("%d %d\n",ans.size(),ans.size());
    for(auto [a,b]:ans)printf("%d %d\n",a,b);
    return 0;
}