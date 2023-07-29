#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base='z'+1;//기저는 max(입력 문자)보다는 커야함.
//해시값 충돌 확률을 줄이기 위해 두개의 소수 사용
const ll mod[2]={1000000007,1000000009};
ll power[2][200000],psum[2][200000];

void init(char *s){
    int n=strlen(s);
    for(int p=0;p<2;p++){
        power[p][0]=1,psum[p][0]=s[0];
        for(int i=1;i<n;i++){
            power[p][i]=power[p][i-1]*base%mod[p];
            psum[p][i]=(psum[p][i-1]+s[i]*power[p][i])%mod[p];
        }
    }
}
ll getHash(int s,int e,int n){//총 길이 n인 문자열에서, 구간[s~e]의 해시값.
    ll ret[2]; if(s>e)return -1;
    for(int p=0;p<2;p++){
        ret[p]=(psum[p][e]-(s?psum[p][s-1]:0)+mod[p])%mod[p];
        ret[p]=ret[p]*power[p][n-1-s]%mod[p];
    }
    return ret[0]*mod[1]+ret[1];//mod[1]>mod[0]이어야함.
}

char st[200001];
int main(){
    int n;scanf("%d %s",&n,st);
    init(st);
    int l=0,r=n,mid,len=0;
    unordered_set<ll> se;
    while(l<=r){
        se.clear(),mid=(l+r)/2;
        bool ok=0;
        for(int s=0,e=s+mid-1;e<n;s++,e++){
            ll hash=getHash(s,e,n);
            ok|=se.find(hash)!=se.end();
            se.insert(hash);
        }
        if(ok)len=max(len,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d",len);
    return 0;
}