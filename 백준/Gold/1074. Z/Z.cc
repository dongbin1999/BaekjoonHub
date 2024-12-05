#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,r,c;
void go(ll sx,ll sy,ll ex,ll ey,ll s,ll e){
    if(s==e){printf("%lld",s);exit(0);}
    vector<array<ll,6>> v;
    ll midx=(sx+ex)/2,midy=(sy+ey)/2,d=e-s;
    v.push_back({sx,sy,midx,midy,s,s+d/4});
    v.push_back({sx,midy+1,midx,ey,s+d/4+1,s+d*2/4});
    v.push_back({midx+1,sy,ex,midy,s+d*2/4+1,s+d*3/4});
    v.push_back({midx+1,midy+1,ex,ey,s+d*3/4+1,e});
    for(int i=0;i<4;i++)if(v[i][0]<=r&&r<=v[i][2]&&v[i][1]<=c&&c<=v[i][3])
        go(v[i][0],v[i][1],v[i][2],v[i][3],v[i][4],v[i][5]);
}

int main(){
    scanf("%lld%lld%lld",&n,&r,&c);
    go(0,0,(1<<n)-1,(1<<n)-1,0,(1ll<<(n*2))-1);
}