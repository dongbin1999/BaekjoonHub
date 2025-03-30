#include<bits/stdc++.h>
using namespace std;

int main(){
    long long s,x,m,d,k,g,ok,mx;cin>>s>>x>>m>>d>>k;
    g=__gcd(x,m);
    s%=g,mx=m-g+s;
    if(!mx)return !printf("0");
    ok=k/mx,cout<<(ok?(d-1)/ok:0);
}