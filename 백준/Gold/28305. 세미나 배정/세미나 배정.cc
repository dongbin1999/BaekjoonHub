#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int main(){
    int n,t;scanf("%d%d",&n,&t);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int l=1,r=n,mid,ans=1e9;
    while(l<=r){
        mid=(l+r)/2;
        priority_queue<int,vector<int>,greater<int>> pq;
        bool b=1;
        for(int i=0;i<mid;i++)pq.push(0);
        for(auto i:v){
            if(pq.top()>=i){
                b=0;break;
            }
            int cur=pq.top();pq.pop();
            pq.push(max(i,cur+t));
        }
        if(b){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}