#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef array<ll,3> arr;

int main(){
    int n;scanf("%d",&n);
    vector<arr> v;
    while(n--){
        char c;scanf(" %c",&c);
        ll C;if(c=='(')C=-1;else if(c==')')C=1;else C=0;
        if(C!=1){v.push_back({C,c-'0',1});continue;}
        vector<pll> p(3);
        for(int i=0;i<3;i++){
            if(v.empty()||v.back()[0]!=0)return !printf("-1");
            p[2-i]={v.back()[1],v.back()[2]},v.pop_back();
        }
        if(v.empty()||v.back()[0]!=-1)return !printf("-1");
        v.pop_back();
        ll y=p[1].second*p[2].first,x=p[1].first*p[2].second;
        p[1]={x/gcd(x,y),y/gcd(x,y)};
        x=p[0].first*p[1].second+p[1].first*p[0].second,y=p[0].second*p[1].second;
        p[0]={x/gcd(x,y),y/gcd(x,y)};
        v.push_back({0,p[0].first,p[0].second});
    }

    if(v.size()!=1||v.back()[0]!=0)return !printf("-1");
    auto [c,x,y]=v.back();
    printf("%lld %lld",x,y);
}