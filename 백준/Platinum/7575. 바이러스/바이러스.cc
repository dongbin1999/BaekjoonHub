#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=10001;
const ll mod[2]={1000000007,1000000009};
ll power[2][1001],psum[2][1001];

void init(vector<int> &s){
    int n=s.size();
    for(int p=0;p<2;p++)for(int i=0;i<n;i++){
            power[p][i]=i?power[p][i-1]*base%mod[p]:1;
            psum[p][i]=i?(psum[p][i-1]+s[i]*power[p][i])%mod[p]:s[0];
        }
}
ll getHash(int s,int e,int n=1000){//총 길이 n인 문자열에서, 구간[s~e]의 해시값.
    ll ret[2]; if(s>e)return -1;
    for(int p=0;p<2;p++){
        ret[p]=(psum[p][e]-(s?psum[p][s-1]:0)+mod[p])%mod[p];
        ret[p]=ret[p]*power[p][n-1-s]%mod[p];
    }
    return ret[0]*mod[1]+ret[1];
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    map<ll,int> ma;
    for(int i=0;i<n;i++){
        set<ll> se;
        int m;scanf("%d",&m);
        vector<int> v(1000);
        for(int j=0;j<m;j++)scanf("%d",&v[j]);
        init(v);
        for(int l=0,r=l+k-1;r<m;l++,r++)
            se.insert(getHash(l,r));
        for(int l=0,r=m-1;l<r;l++,r--)
            swap(v[l],v[r]);
        init(v);
        for(int l=0,r=l+k-1;r<m;l++,r++)
            se.insert(getHash(l,r));
        for(auto j:se)ma[j]++;
    }
    for(auto [a,b]:ma)
        if(b==n)return !printf("YES");
    printf("NO");
    return 0;
}