#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll a[100002],u[100002],b[100002];
pll lr[100002];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],lr[x]=lr[y]={min(lr[x].first,lr[y].first),max(lr[x].second,lr[y].second)},u[y]=x;
    return 1;
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<pll> v;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end(),greater<pll>());
    for(int i=0;i<=n+1;i++)lr[i]={i,i},b[i]=1;
    memset(u,-1,sizeof(u));
    ll ans=0;
    for(auto [val,idx]:v){
        b[idx]=0;
        if(!b[idx-1])merge(idx,idx-1);
        if(!b[idx+1])merge(idx,idx+1);
        auto [l,r]=lr[find(idx)];
        vector<ll> L={idx+1,l},R={idx-1,r};
        while(L.size()<=k+3){
            l=find(lr[l].first-1);if(l<1)break;
            if(!b[l])L.back()=lr[l].first;
            else L.push_back(lr[l].first);
        }
        while(R.size()<=k+3){
            r=find(lr[r].second+1);if(r>n)break;
            if(!b[r])R.back()=lr[r].second;
            else R.push_back(lr[r].second);
        }
        l=k-1,r=0;ll add=0;
        while(r<k){
            if(L.size()>l+1&&R.size()>r+1)
                add+=(L[l]-L[l+1])*(R[r+1]-R[r]);
            l--,r++;
        }
        ans+=val*add;
    }
    printf("%lld",ans);
}