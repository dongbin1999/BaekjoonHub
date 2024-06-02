#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<vector<ll>> mat;
pii go[4]={{1,0},{-1,0},{0,1},{0,-1}};
const ll mod=1e9+7;

mat mul(mat a, mat b){
    //a:x*y행렬, b:y*z행렬 -> 결과 : x*z행렬. 여기서는 x==y==z.
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

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    int n=grid.size(),m=grid[0].size();
    //matrix a: x에서 시작해서, 경사수열을 1번 완주하고 y에 도착하는 경우의수.
    mat a(n*m,vector<ll>(n*m));
    
    for(int S=0;S<n*m;S++){
        vector<ll> v(n*m);v[S]=1;
        for(auto s:d){
            vector<ll> nv(n*m);
            for(int i=0;i<n*m;i++){
                int x=i/m,y=i%m;
                for(auto [dx,dy]:go){
                    int nx=x+dx,ny=y+dy;
                    if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]-grid[x][y]!=s)continue;
                    nv[nx*m+ny]=(nv[nx*m+ny]+v[i])%mod;
                }
            }
            v=nv;
        }
        for(int E=0;E<n*m;E++)a[S][E]=v[E];
    }
    mat result=power(a,k);
    ll ans=0;
    for(int i=0;i<n*m;i++)for(int j=0;j<n*m;j++)ans+=result[i][j];
    return ans%mod;
}