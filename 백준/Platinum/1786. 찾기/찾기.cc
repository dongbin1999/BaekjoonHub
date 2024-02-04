#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=300;
const ll mod[2]={1000000007,1000000009};
ll power[2][1000001],psum[2][1000001];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string T,P;getline(cin,T),getline(cin,P);
    if(T.size()<P.size())return !printf("0");
    init(T);
    ll h[2]={0};
    for(int i=0;i<P.size();i++)
        for(int p=0;p<2;p++)
            h[p]=(h[p]+P[i]*power[p][i])%mod[p];
    for(int p=0;p<2;p++)h[p]=h[p]*power[p][T.size()-1]%mod[p];
    ll hash=h[0]*mod[1]+h[1];
    vector<int> ans;

    for(int l=0,r=l+P.size()-1;r<T.size();l++,r++)
        if(getHash(l,r,T.size())==hash)ans.push_back(l+1);
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
    return 0;
}