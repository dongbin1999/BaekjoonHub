#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2][8][101];
string s;
map<char,int> ma;

int main(){
    ma['A']=ma['E']=ma['I']=ma['O']=ma['U']=1;
    cin>>s;
    if(s[0]=='_')dp[1][6][0]=1,dp[0][6][0]=20,dp[0][1][0]=5;
    else dp[s[0]=='L'][ma[s[0]]?1:6][0]=1;
    for(int i=0;i<(int)s.size()-1;i++)for(int l=0;l<2;l++)for(int j=1;j<7;j++){
        if(s[i+1]=='_'){
            dp[1][(j*2)%8][i+1]+=dp[l][j][i];
            dp[l][(j*2)%8][i+1]+=dp[l][j][i]*20;
            dp[l][(j*2+1)%8][i+1]+=dp[l][j][i]*5;
        }
        else{
            dp[l||s[i+1]=='L'][(j*2+ma[s[i+1]])%8][i+1]+=dp[l][j][i];
        }
    }
    ll ans=0;
    for(int i=1;i<7;i++)ans+=dp[1][i][(int)s.size()-1];
    printf("%lld",ans);
    return 0;
}