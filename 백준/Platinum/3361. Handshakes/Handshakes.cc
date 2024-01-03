#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;cin>>s;
    ll r=0,l=0,a=0,b=0;
    for(auto i:s){
        ll L=i=='L';
        r+=!L,l+=L;
        if(L)b+=r;
    }
    reverse(s.begin(),s.end());
    r=0,l=0;ll d=0;
    for(auto i:s){
        ll R=i=='R';
        r+=R,l+=!R;
        if(l&&R)a=max(a,l+d),d++;
        else d=max(0ll,d-1);
    }
    printf("%lld %lld",a,b);
    return 0;
}