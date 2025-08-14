#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int x,n;scanf("%d%d",&x,&n);
    vector<ll> v(x);
    for(auto &i:v)scanf("%lld",&i);
    ll sum=accumulate(v.begin(),v.begin()+n,0ll);
    pll ans={sum,1};
    for(int i=n;i<x;i++){
        sum+=v[i]-v[i-n];
        if(ans.first<sum)ans={sum,1};
        else if(ans.first==sum)ans.second++;
    }
    auto [a,b]=ans;
    if(!a)return !printf("SAD");
    printf("%lld\n%lld",a,b);
}