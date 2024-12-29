#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t=0;
void solve(){
    printf("Scenario #%d:\n",++t);
    ll p,q;scanf("%lld%lld",&p,&q);
    int ans=1;
    while(1){
        if(p<0){
            p*=-1;
            ll d=(q-1)/2;
            if(d%2)ans*=-1;
        }
        if(p==1)break;
        while(p%4==0)p/=4;
        if(p%2==0){
            p/=2;
            ll d=(q*q-1)/8;
            if(d%2)ans*=-1;
        }
        if(p==1)break;
        if(p<q){
            swap(p,q);
            ll d=(p-1)*(q-1)/4;
            if(d%2)ans*=-1;
        }
        p%=q;
        if(p%2)p-=q;
        if(p==1)break;
    }
    printf("%d\n\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}