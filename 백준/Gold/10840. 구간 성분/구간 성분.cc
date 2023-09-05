#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=1501;
const ll mod[2]={1000000007,1000000009};
ll power[26][2],psum[1500][2][2];
char a[1503],b[1503];

void init(char *s,bool c){
    int n=strlen(s);
    for(int p=0;p<2;p++)
        for(int i=0;i<n;i++)
            psum[i][p][c]=i?(psum[i-1][p][c]+power[s[i]-'a'][p])%mod[p]:power[s[0]-'a'][p];
}
ll getHash(int s,int e,bool c){
    ll ret[2]; if(s>e)return -1;
    for(int p=0;p<2;p++)
        ret[p]=(psum[e][p][c]-(s?psum[s-1][p][c]:0)+mod[p])%mod[p];
    return ret[0]*mod[1]+ret[1];
}

int main(){
    for(int i=0;i<26;i++)for(int p=0;p<2;p++)
        power[i][p]=i?power[i-1][p]*base%mod[p]:1;
    scanf("%s %s",a,b);
    int n=strlen(a),m=strlen(b);
    init(a,0),init(b,1);
    for(int len=min(n,m);len>=1;len--){
        set<ll> se;
        for(int l=0,r=len-1;r<n;l++,r++)se.insert(getHash(l,r,0));
        for(int l=0,r=len-1;r<m;l++,r++)if(se.count(getHash(l,r,1)))return !printf("%d",len);
    }
    printf("0");
    return 0;
}