#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,ll> tup;
typedef pair<int,int> pii;
const int sz=300000;

vector<int> idx[sz+1];
int ans[sz+1],n,m;
pii lr[sz+1];
tup q[sz+1];

ll BIT[sz+1],p[sz+1];
ll query(int i){ll x=0;while(i)x+=BIT[i],i-=i&-i;return x;}
void update(int i,ll x){while(i<=sz)BIT[i]+=x,i+=i&-i;}
void update(int l,int r,ll x){update(l,x);if(r<sz)update(r+1,-x);}

void pbs(){
    memset(BIT,0,sizeof(BIT));
    vector<pii> v;
    for(int i=1;i<=n;i++)v.push_back({lr[i].first+lr[i].second>>1,i});
    sort(v.begin(),v.end());
    int qidx=1;
    for(auto [mid,i]:v){
        while(qidx<=mid){
            auto [l,r,a]=q[qidx++];
            if(l>r)update(l,m,a),update(1,r,a);
            else update(l,r,a);
        }
        __int128 sum=0;
        for(auto o:idx[i])sum+=query(o);
        if(sum>=p[i])ans[i]=min(ans[i],mid),lr[i].second=mid-1;
        else lr[i].first=mid+1;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int o;scanf("%d",&o);
        idx[o].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
    int Q;scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        int l,r;ll a;scanf("%d%d%lld",&l,&r,&a);
        q[i]={l,r,a};
    }
    fill(lr,lr+n+1,pii{1,Q});
    memset(ans,0x3f,sizeof(ans));
    int iter=ceil(log2(Q))+1;
    while(iter--)pbs();
    for(int i=1;i<=n;i++)
        if(ans[i]>1e9)printf("NIE\n");
        else printf("%d\n",ans[i]);
}