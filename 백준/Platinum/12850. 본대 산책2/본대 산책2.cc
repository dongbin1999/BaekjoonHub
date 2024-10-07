#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;

mat mul(mat a, mat b){
    mat ret(a.size(),vector<ll>(b[0].size()));
    for(int x=0;x<a.size();x++)for(int z=0;z<b[0].size();z++){
            ll val=0;
            for(ll y=0;y<b.size();y++)val+=a[x][y]*b[y][z]%mod;
            ret[x][z]=val%mod;
        }
    return ret;
}

mat power(mat a, ll d){
    int nm=a.size();
    mat ret(nm,vector<ll>(nm));
    for(int i=0;i<nm;i++)ret[i][i]=1;
    while(d){
        if(d%2)ret=mul(ret,a);
        a=mul(a,a);
        d/=2;
    }
    return ret;
}

int main() {
    ll d;scanf("%lld",&d);
    mat a(8,vector<ll>(8));
    a[0][1]=a[1][0]=1;
    a[0][2]=a[2][0]=1;
    a[1][2]=a[2][1]=1;
    a[1][3]=a[3][1]=1;
    a[2][3]=a[3][2]=1;
    a[2][4]=a[4][2]=1;
    a[3][4]=a[4][3]=1;
    a[5][3]=a[3][5]=1;
    a[5][4]=a[4][5]=1;
    a[7][5]=a[5][7]=1;
    a[7][6]=a[6][7]=1;
    a[4][6]=a[6][4]=1;
    printf("%lld",power(a,d)[0][0]);
}