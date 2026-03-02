#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;scanf("%lld",&n);
    int ans=0;
    while(n>1){
        if(n%2)n=n*3+1;
        else n>>=1;
        ans++;
    }
    printf("%d",ans);
}