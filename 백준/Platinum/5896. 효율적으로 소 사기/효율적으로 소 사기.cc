#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,3> tup;
int main(){
    int n,k;ll m;scanf("%d%d%lld",&n,&k,&m);
    priority_queue<tup,vector<tup>,greater<tup>> P,C;
    priority_queue<ll,vector<ll>,greater<ll>> rollback;
    vector<int> checked(n);
    for(int i=0;i<n;i++){
        ll p,c;scanf("%lld%lld",&p,&c);
        P.push({p,c,i}),C.push({c,p,i});
    }
    int ans=0;
    while(ans<n){
        while(checked[C.top()[2]])C.pop();
        while(checked[P.top()[2]])P.pop();
        auto [p1,c1,i1]=P.top();
        auto [c2,p2,i2]=C.top();
        if(k){
            if(c2>m)break;
            k--,ans++,m-=c2,C.pop(),checked[i2]=1,rollback.push(p2-c2);
            continue;
        }
        ll r=rollback.top();
        if(c2+r<p1){//쿠폰 되돌려서 사기
            if(c2+r>m)break;
            ans++,m-=c2+r,C.pop(),rollback.pop(),checked[i2]=1,rollback.push(p2-c2);
        }
        else{//그냥사기
            if(p1>m)break;
            ans++,m-=p1,P.pop(),checked[i1]=1;
        }
    }
    printf("%d",ans);
    return 0;
}