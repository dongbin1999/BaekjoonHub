#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
map<pll,ll> ma;
int main(){
    int n;scanf("%d",&n);
    deque<pll> dq(n);
    ll a=0,b=0;
    for(auto &[x,y]:dq){
        scanf("%lld%lld",&x,&y);
        a+=x,b+=y,ma[{x,y}]++;
    }
    if(n%2||a%(n/2)||b%(n/2))return !printf("impossible");
    a/=n/2,b/=n/2;
    for(auto [x,y]:dq){
        if(ma[{a-x,b-y}]<=0)return !printf("impossible");
        ma[{a-x,b-y}]--;
    }
    printf("possible");
}