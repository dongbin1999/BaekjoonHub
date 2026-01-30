//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,3> arr;
const ll mod=1e9+7;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x);
    reverse(v.begin(),v.end());
    int s=0,a=0,ans=0;
    for(int i=0;i<n;i++){
        if(!i)a++,ans+=a;
        else{
            int ss=v[i]>v[i-1];
            if(v[i]<v[i-1])ss=-1;
            if(!ss)a=1,ans+=a;
            else if(s*ss==-1)a++,ans+=a,s=ss;
            else a=2,ans+=a,s=ss;
        }
    }
    printf("%d",ans);
    return 0;
}