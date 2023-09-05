#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=19;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll a[1<<sz];
ll sparse[1<<sz][sz];
void init(int n){
    for(int i=n;i>=1;i--)
        for(int j=0;j<sz;j++)
            sparse[i][j]=j?GCD(sparse[i][j-1],sparse[min(n,i+(1<<(j-1)))][j-1]):GCD(a[i],a[i+1]);
}
ll get_far(ll gcd,ll idx){
    for(int i=sz-1;i>=0;i--)
        if(GCD(gcd,sparse[idx][i])==gcd)
            idx+=1<<i;
    return idx;
}
int main(){
    int n;scanf("%d",&n);
    unordered_set<ll> se;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),se.insert(a[i]);
    a[n+1]=1;//범위를 넘어가면 gcd를 1로 만들기 위함.
    init(n);
    for(int i=1;i<=n;i++){
        ll gcd=a[i],cur=i;
        while(gcd>1){
            ll idx=get_far(gcd,cur);
            if(idx<=n){
                gcd=GCD(gcd,sparse[idx][0]);
                if(idx<n)se.insert(gcd);
                cur=idx+1;
            }
        }
    }
    printf("%d",se.size());
    return 0;
}