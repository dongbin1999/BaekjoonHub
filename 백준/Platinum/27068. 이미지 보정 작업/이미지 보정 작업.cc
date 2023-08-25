#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tup;
pll go[4]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    ll n,m,k,x;scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    vector<tup> temp;
    vector<ll> vvv(m);
    vector<vector<ll>> vv(n,vvv);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
            scanf("%lld",&vv[i][j]),temp.push_back({vv[i][j],i,j});
    sort(temp.begin(),temp.end());
    ll l=0,r=x,mid,ans=x;
    while(l<=r){
        vector<tup> p=temp;
        vector<vector<ll>> v=vv;
        mid=(l+r)/2;
        ll correct=0;
        for(int i=0;i<n*m&&correct<=k;i++){
            auto[val,cx,cy]=p[i];
            if(val>=x-mid||val!=v[cx][cy])continue;
            bool ok=1;
            for(auto [dx,dy]:go){
                ll nx=cx+dx,ny=cy+dy;
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                ok&=abs(v[nx][ny]-val)<=mid;
            }
            if(!ok){
                queue<pll> q;
                v[cx][cy]=x,correct++;q.push({cx,cy});
                while(!q.empty()){
                    auto [xx,yy]=q.front();q.pop();
                    for(auto [dx,dy]:go){
                        ll nx=xx+dx,ny=yy+dy;
                        if(nx<0||nx>=n||ny<0||ny>=m||v[nx][ny]>=x-mid)continue;
                        v[nx][ny]=x,correct++;q.push({nx,ny});
                    }
                }
            }
        }
        if(correct<=k)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
    return 0;
}