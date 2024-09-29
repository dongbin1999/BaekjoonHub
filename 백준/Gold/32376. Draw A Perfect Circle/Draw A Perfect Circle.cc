#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
map<ll,ll> ma;
int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++){
        ll x,y;scanf("%lld%lld",&x,&y);
        ma[x*x+y*y]++;
    }
    deque<pll> dq;ll cnt=0,mx=0,LL=-1,RR=0;
    for(auto [DD,num]:ma){
        cnt+=num,RR=DD,dq.push_back({DD,num});
        if(LL==-1){LL=RR,mx=cnt;continue;}
        while(1){
            /*l+k>=r?
             * -> l^2+2lk+k^2>=r^2?
             * -> 2lk>=r^2-k^2-l^2? (r^2-k^2-l^2<0이면 만족. right<0 체크하지 않고 계산한 코드 저격.)
             * -> 4l^2k^2>=(r^2-k^2-l^2)^2?*/
            ll right=RR-k*k-LL;
            if(right<0||LL*k*k*4>=right*right) break;
            else {
                cnt-=dq.front().second,dq.pop_front();
                LL=dq.front().first;
                continue;
            }
        }
        mx=max(mx,cnt);
    }
    printf("%.15lf",(double)mx*100.0/(double)n);
    return 0;
}