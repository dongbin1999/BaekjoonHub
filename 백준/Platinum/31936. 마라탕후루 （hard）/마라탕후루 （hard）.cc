#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef array<ll,3> tup;
ll a[1000001],b[1000001];
pll ab[2000001];

int main(){
    int n;ll p,q;scanf("%d%lld%lld",&n,&p,&q);
    ll GCD=gcd(p,q);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    memset(ab,-1,sizeof(ab));
    ll mid=1e6;
    queue<tup> qu;qu.push({mid,0,0}),ab[0]={0,0};
    while(!qu.empty()){
        auto [val,A,B]=qu.front();qu.pop();
        for(ll da=-1;da<=1;da++)for(ll db=-1;db<=1;db++){
            ll nval=val+da*p-db*q,na=A+da,nb=B+db;
            if(na>=0&&nb>=0&&nval<=2e6&&nval>=0&&ab[nval].first==-1)
                ab[nval]={na,nb},qu.push({nval,na,nb});
        }
    }
    ll A=0,B=0;
    vector<pll> ans(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
        if(ab[b[i]-a[i]+mid].first==-1)return !printf("NO");
        ans[i]=ab[b[i]-a[i]+mid];
        A+=ans[i].first,B+=ans[i].second;
    }
    if(A>B){
        ll diff=A-B,dp=q/GCD,dq=p/GCD;
        if(dp>=dq)return !printf("NO");
        if(diff%(dq-dp))return !printf("NO");
        ll iter=diff/(dq-dp);
        ans[0].first+=iter*dp,ans[0].second+=iter*dq;
    }
    if(A<B){
        ll diff=B-A,dp=q/GCD,dq=p/GCD;
        if(dp<=dq)return !printf("NO");
        if(diff%(dp-dq))return !printf("NO");
        ll iter=diff/(dp-dq);
        ans[0].first+=iter*dp,ans[0].second+=iter*dq;
    }
    printf("YES\n");
    for(auto [x,y]:ans)printf("%lld ",x);
    printf("\n");
    for(auto [x,y]:ans)printf("%lld ",y);
    printf("\n");
}