#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;char s[20];

bool check(int x){
    for(int j=0;j<n;j++)if((x>>j)&(x>>(j+1))&1)return false;
    return true;
}
ll cal(ll x,ll y,char op){
    if(op=='+')return x+y;
    else if(op=='-') return x-y;
    else return x*y;
}

int main(){
    scanf("%d %s",&n,s);
    vector<ll> num;
    vector<char>op={'+'};
    for(int i=0;i<n;i++)
        if(i%2)op.push_back(s[i]);
        else num.push_back(s[i]-'0');
    n=n/2+1;
    ll ans=-2e18;
    for(int i=1<<n;i<2<<n;i++){
        if(!check(i))continue;
        ll tmp=0;
        for(int j=0;j<n;j++){
            ll x=num[j];char c=op[j];
            if(i>>j&1)j++,x=cal(x,num[j],op[j]);
            tmp=cal(tmp,x,c);
        }
        ans=max(ans,tmp);
    }
    printf("%lld",ans);
    return 0;
}