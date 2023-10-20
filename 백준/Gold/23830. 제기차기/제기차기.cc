#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    ll p,q,r,s;scanf("%lld%lld%lld%lld",&p,&q,&r,&s);
    ll le=1,ri=2e12,mid,ans=2e18;
    while(le<=ri){
        mid=(le+ri)/2;
        ll score=0;
        for(int i=0;i<n;i++){
            if(v[i]>mid+r)score+=v[i]-p;
            else if(v[i]<mid)score+=v[i]+q;
            else score+=v[i];
        }
        if(score>=s)ans=min(ans,mid),ri=mid-1;
        else le=mid+1;
    }
    printf("%lld",ans==2e18?-1:ans);
    return 0;
}