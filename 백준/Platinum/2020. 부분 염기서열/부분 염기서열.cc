#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=300;
const ll mod[2]={1000000007,1000000009};
ll power[2][1001],psum[2][1001];

void init(string &s){
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
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    string s;cin>>s;
    init(s);
    unordered_map<ll,int> ma,tma;
    int anslen=1e9,kk;
    ll cnt=0;
    for(int len=1;len<=n;len++){
        ll tmp=0;
        for(int l=0,r=l+len-1;r<n;l++,r++)
            tmp+=++tma[getHash(l,r,n)]==m;
        if(tmp>=k){if(anslen==1e9)anslen=len,ma=tma,kk=k;}
        else k-=tmp;
        tma.clear(),cnt+=tmp;
    }
    cout<<cnt<<endl;
    for(int l=0,r=l+anslen-1;r<n;l++,r++){
        if(ma[getHash(l,r,n)]<m)continue;
        ll tmp=0;
        string ans=s.substr(l,anslen);
        unordered_set<ll> vis;
        for(int nl=0,nr=nl+anslen-1;nr<n;nl++,nr++){
            if(vis.count(getHash(nl,nr,n))||ma[getHash(nl,nr,n)]<m)continue;
            vis.insert(getHash(nl,nr,n));
            tmp+=ans>=s.substr(nl,anslen);
        }
        if(tmp==kk){cout<<ans;return 0;}
    }
    return 0;
}