#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[1501][26][2];
ll base=1501,mod[2]={1000000007,1000000009};
ll getHash(vector<int> v){
    ll ret[2]={0};
    for(int p=0;p<2;p++)
        for(int i=0;i<26;i++)
            ret[p]=(ret[p]*base+v[i])%mod[p];
    return ret[0]*mod[1]+ret[1];
}

int main(){
    string a,b;cin>>a>>b;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<26;j++)
            sum[i][j][0]=(a[i]-'a'==j)+(i?sum[i-1][j][0]:0);
    for(int i=0;i<b.size();i++)
        for(int j=0;j<26;j++)
            sum[i][j][1]=(b[i]-'a'==j)+(i?sum[i-1][j][1]:0);
    map<ll,int> ma;
    for(int l=0;l<a.size();l++)for(int r=l;r<a.size();r++){
            vector<int> v(26);
            for(int i=0;i<26;i++)v[i]=sum[r][i][0]-(l?sum[l-1][i][0]:0);
            ma[getHash(v)]=r-l+1;
        }
    int ans=0;
    for(int l=0;l<b.size();l++)for(int r=l;r<b.size();r++){
            vector<int> v(26);
            for(int i=0;i<26;i++)v[i]=sum[r][i][1]-(l?sum[l-1][i][1]:0);
            ans=max(ans,ma[getHash(v)]);
        }
    printf("%d",ans);
    return 0;
}