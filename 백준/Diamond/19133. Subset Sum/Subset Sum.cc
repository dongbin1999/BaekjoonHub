#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
int main() {
    int n,k;scanf("%d%d",&n,&k);
    ll base=0,empty=0;
    vector<ll> v;
    while(n--){
        ll x;scanf("%lld",&x);
        if(x<0)base+=x,v.push_back(-x);
        else v.push_back(x);
    }
    sort(v.begin(),v.end());
    priority_queue<pli,vector<pli>,greater<pli>>pq;
    if(!base)empty=1;
    else printf("%lld\n",base),k--;
    pq.push({v[0],0});
    while(1){
        auto[sum,l]=pq.top();pq.pop();
        if(l+1<v.size())pq.push({sum-v[l]+v[l+1],l+1}),pq.push({sum+v[l+1],l+1});
        if(sum+base==0&&!empty){empty=1;continue;}
        printf("%lld\n",sum+base),k--;
        if(!k)break;
    }
}