#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=10000000;
const ll mod=2000003;
bool no_prime[sz+1]={true,true};
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(){
    int n;scanf("%d",&n);
    for(int i=2;i<=sz;i++)
        if(!no_prime[i]){
            pq.push(i);
            for(int j=i*2;j<=sz;j+=i)
                no_prime[j]=true;
        }
    ll ans=1;
    while(n--){
        ll x=pq.top();pq.pop();
        ans=(ans*x)%mod;
        pq.push(x*x);
    }
    printf("%lld",ans);
    return 0;
}