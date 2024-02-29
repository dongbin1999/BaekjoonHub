#include <bits/stdc++.h>
using namespace std;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
typedef long long ll;
typedef tuple<ll,ll,ll> tup;

int main(){
    int n;scanf("%d",&n);
    vector<tup> v(n);
    vector<ll> xv,yv;
    for(auto &[x,y,z]:v){
        scanf("%lld%lld%lld",&x,&y,&z);
        xv.push_back(x);
        yv.push_back(y);
    }
    UNIQUE(xv),UNIQUE(yv);

    ll ans=1e9;
    for(int lx=0;lx<xv.size();lx++)for(int rx=lx;rx<xv.size();rx++)for(int ly=0;ly<yv.size();ly++)for(int ry=ly;ry<yv.size();ry++){
        ll xl=xv[lx],xr=xv[rx],yl=yv[ly],yr=yv[ry],
        need=(xr-xl+yr-yl)*2,len=0,tmp=0;
        priority_queue<ll> pq;
        for(auto[x,y,z]:v)
            if(xl<=x&&x<=xr&&yl<=y&&y<=yr)pq.push(z);
            else tmp++,len+=z;
        while(!pq.empty()&&need>len)
            len+=pq.top(),pq.pop(),tmp++;
        if(need<=len)ans=min(ans,tmp);
    }
    printf("%lld",ans);
    return 0;
}