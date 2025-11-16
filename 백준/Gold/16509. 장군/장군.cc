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

pii go[8]={{3,2},{-3,-2},{-3,2},{3,-2},{2,3},{-2,-3},{2,-3},{-2,3}};
pii chk[8]={{2,1},{-2,-1},{-2,1},{2,-1},{1,2},{-1,-2},{1,-2},{-1,2}};
int v[20][20];
void solve(){
    pii k,s;cin>>s.first>>s.second>>k.first>>k.second;
    memset(v,-1,sizeof(v));
    queue<arr> q;
    v[s.first][s.second]=0,q.push({s.first,s.second,0});
    while(!q.empty()){
        auto [x,y,d]=q.front();q.pop();
        for(int i=0;i<8;i++){
            auto [dx,dy]=go[i];auto [cx,cy]=chk[i];
            int nx=x+dx,ny=y+dy;
            if(nx<0||nx>9||ny<0||ny>8||v[nx][ny]!=-1)continue;
            if(x+cx==k.first&&y+cy==k.second)continue;
            v[nx][ny]=d+1,q.push({nx,ny,d+1});
        }
    }
    cout<<v[k.first][k.second];
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}