#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long i128;
int main(){
    while(1){
        ll x;cin>>x;
        if(!x)break;
        for(ll i=31;i>=1;i--){
            ll mx=pow(abs(x),1.0/i)+2;
            bool ok=0;
            for(ll j=max(0ll,mx-4);j<=mx;j++){
                i128 d=1,ii=i;while(ii--)d*=j;
                if(d==x){ok=1;break;}
            }
            for(ll j=-mx;j<=min(0ll,-mx+4);j++){
                i128 d=1,ii=i;while(ii--)d*=j;
                if(d==x){ok=1;break;}
            }
            if(ok){cout<<i<<endl;break;}
        }
    }
}