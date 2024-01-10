#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> s;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        if(s.empty()||s.back()>x)
            s.push_back(x);
        else{
            ans+=x-s.back();
            while(!s.empty()&&s.back()<=x)s.pop_back();
            s.push_back(x);
        }
    }
    ans+=*s.begin()-s.back();
    printf("%lld",ans);
}