#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%MOD;a=a*a%MOD;b/=2;}return ret;}
const int sz = 1<<17;

char s[3000];
bool pal[3000][3000];
int dp[3000];

int main()
{
    scanf("%s",s+1);
    int ss = strlen(s+1);
    for(int i=1;i<=ss;i++)
    {
        pal[i][i]=true;
        int l=i-1,r=i+1;
        while(l>=1 && r<=ss)
        {
            if(s[l]==s[r])
                pal[l][r] = true;
            else
                break;
            l--,r++;
        }
        if(s[i] == s[i+1])
        {
            pal[i][i+1]=true;
            l=i-1,r=i+2;
            while(l>=1 && r<=ss)
            {
                if(s[l]==s[r])
                    pal[l][r] = true;
                else
                    break;
                l--,r++;
            }
        }
    }

    for(int i=2;i<=ss+1;i++)
        dp[i]=1e9;
    for(int l=1;l<=ss;l++)
        for(int r=l;r<=ss;r++)
            if(pal[l][r])
                dp[r+1]=min(dp[r+1],dp[l]+1);

    printf("%d",dp[ss+1]);
    return 0;
}