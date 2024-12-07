#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define add(a,b) a=(a+b)%mod;
int main(){
    int n;scanf("%d",&n);
    vector<ll> x(6),y;x[0]=1;
    while(n--){
        char c;scanf(" %c",&c);
        y=x;
        if(c=='W'){
            add(y[1],x[0]);
        }
        else if(c=='H'){
            add(y[2],x[1]);
        }
        else if(c=='E'){
            add(y[3],x[2]);
            add(y[4],x[3]+x[4]);
        }
        x=y;
    }
    printf("%lld",x[4]);
}