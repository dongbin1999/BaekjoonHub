#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=0;
        pll cmp={1,0};
        for(int j=i-1;j>=0;j--){
            auto [xx,yy]=cmp;
            ll x=v[i]-v[j],y=abs(i-j);
            tmp+=xx*y>x*yy;
            if(xx*y>x*yy)cmp={x,y};
        }
        cmp={1,0};
        for(int j=i+1;j<n;j++){
            auto [xx,yy]=cmp;
            ll x=v[i]-v[j],y=abs(i-j);
            tmp+=xx*y>x*yy;
            if(xx*y>x*yy)cmp={x,y};
        }
        ans=max(ans,tmp);
    }
    printf("%d",ans);
    return 0;
}