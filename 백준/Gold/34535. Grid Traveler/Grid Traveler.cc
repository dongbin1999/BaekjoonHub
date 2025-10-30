#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tup;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}

int a[1000][1000];

int main(){
    int n;scanf("%d",&n);
    printf("YES\n");
    int x=0,y=0,d=1,z=0;
    vector<pii> v;
    while(1){
        v.push_back({x,y});
        a[x][y]=++z,y+=d;
        if(y==n||y==-1)x++,d*=-1,y+=d;
        if(x==n)break;
    }
    for(int i=2;i+1<v.size();i+=4){
        auto [x1,y1]=v[i];
        auto [x2,y2]=v[i+1];
        swap(a[x1][y1],a[x2][y2]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}