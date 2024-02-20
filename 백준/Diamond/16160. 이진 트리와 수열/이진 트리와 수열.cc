#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=100001;
const ll mod[2]={1000000007,1000000009};
ll power[2][400001],psum[2][400001];

void init(vector<ll> &s){
    int n=s.size();
    for(int p=0;p<2;p++)for(int i=0;i<n;i++){
            power[p][i]=i?power[p][i-1]*base%mod[p]:1;
            psum[p][i]=i?(psum[p][i-1]+s[i]*power[p][i])%mod[p]:s[0];
        }
}
ll getHash(int s,int e,int n){//총 길이 n인 문자열에서, 구간[s~e]의 해시값.
    ll ret[2]; if(s>e)return -1;
    for(int p=0;p<2;p++){
        ret[p]=(psum[p][e]-(s?psum[p][s-1]:0)+mod[p])%mod[p];
        ret[p]=ret[p]*power[p][n-1-s]%mod[p];
    }
    return ret[0]*mod[1]+ret[1];
}

int main(){
    ll h,n,k;scanf("%lld%lld%lld",&h,&n,&k);
    vector<ll> v(n+n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]),v[i+n]=v[i];
    init(v);
    int l=1,r=h,rr=r,mid,ans=1e9;
    while(l<=r){
        mid=(l+r)/2;
        ll len=1ll<<(rr-mid),cnt=1ll<<(mid-1);
        map<ll,ll> ma;
        for(int i=0;i<n;i++){
            ll s=len%n*i%n;
            ll hash=getHash(s,s+min(n,len)-1,n+n);
            ma[hash]+=cnt/n+(i%n<cnt%n);
        }
        bool b=0;
        for(auto [x,y]:ma)b|=y>=k;
        if(b)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans==1e9?-1:ans);
    return 0;
}