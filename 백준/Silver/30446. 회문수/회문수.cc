#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;scanf("%lld",&n);
    ll ans=0;
    for(int i=1;i<=100000;i++){
        string s=to_string(i),r=s;
        reverse(r.begin(),r.end());
        string ss=s;
        s+=r,ss.pop_back(),ss+=r;
        if(stoll(s)<=n)ans++;
        if(stoll(ss)<=n)ans++;
    }
    printf("%lld",ans);
}