#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x,y;scanf("%lld%lld",&x,&y);
    priority_queue<ll> a,b;
    a.push(0),b.push(0);
    ll n=(1ll<<60)-1;
    while(x){
        if(n<=x)x-=n,a.push(n);
        else n>>=1;
    }
    n=(1ll<<60)-1;
    while(y){
        if(n<=y)y-=n,b.push(n);
        else n>>=1;
    }
    while((int)a.size()-(int)b.size()>1){
        ll m=b.top();b.pop();
        if(m<=1)break;
        b.push(m>>1),b.push(m>>1),b.push(1);
    }
    while((int)b.size()-(int)a.size()>1){
        ll m=a.top();a.pop();
        if(m<=1)break;
        a.push(m>>1),a.push(m>>1),a.push(1);
    }
    if(abs((int)a.size()-(int)b.size())>1)return !printf("impossible");
    int cnt=0;
    bool s=a.size()>b.size();
    while(!a.empty()||!b.empty()){
        if(!(s?a:b).empty()){
            ll m=(s?a:b).top();(s?a:b).pop();
            while(m)printf(s?"R":"U"),m>>=1,cnt++;
        }
        if(!(s?b:a).empty()){
            ll m=(s?b:a).top();(s?b:a).pop();
            while(m)printf(s?"U":"R"),m>>=1,cnt++;
        }
    }
    assert(cnt<=4000);
}