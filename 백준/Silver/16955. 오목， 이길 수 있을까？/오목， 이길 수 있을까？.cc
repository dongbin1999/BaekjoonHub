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

char s[12][12];
bool chk(){
        for(int r=0;r<10;r++)
            for(int c=0;c<10;c++){
                int x=0,y=0,z=0,w=0;
                for(int k=0;k<5;k++){
                    if(r+k>=10||c+k>=10)break;
                    x+=s[r+k][c+k]=='X';
                }
                for(int k=0;k<5;k++){
                    if(r+k>=10||c-k<0)break;
                    y+=s[r+k][c-k]=='X';
                }
                for(int k=0;k<5;k++){
                    if(r+k>=10)break;
                    z+=s[r+k][c]=='X';
                }
                for(int k=0;k<5;k++){
                    if(c+k>=10)break;
                    w+=s[r][c+k]=='X';
                }
                if(x>=5||y>=5||z>=5||w>=5)return 1;
            }
    return 0;
}

void solve(){
    for(int i=0;i<10;i++)scanf("%s",s[i]);
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        if(s[i][j]!='.')continue;
        s[i][j]='X';
        if(chk()){printf("1");return;}
        s[i][j]='.';
    }
    printf("0");
}

int main(){
    int tc=1;
    while(tc--)solve();
    return 0;
}