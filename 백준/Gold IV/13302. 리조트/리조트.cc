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

int dp[106][106][54];//n일 중 i일까지 봤는데 지금까지 j일을 이용했고, 쿠폰 k장 들고있을때 최솟값
int no[106],sum[106];

int able(int l, int r)
{
    return sum[r]-sum[l-1];
}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    int n,m;
    scanf("%d %d",&n,&m);
    int played=n-m;
    while(m--)
    {
        int a; scanf("%d",&a);
        no[a]++;
    }
    for(int i=n+1;i<=n+5;i++)
        no[i]=1;
    for(int i=1;i<=n+5;i++)
        sum[i]=sum[i-1]+(1-no[i]);
    dp[0][0][0]=0;
    for(int day=0;day<n;day++)
        for(int play=0;play<=day;play++)
            for(int coupon=0;coupon<=day/2;coupon++)
            {
                int go[5][4]={{day+1,play+able(day+1,day+1),coupon,10000},{day+1,play+able(day+1,day+1),coupon-3,0}
                ,{day+3,play+able(day+1,day+3),coupon+1,25000},{day+5,play+able(day+1,day+5),coupon+2,37000},{day+1,play,coupon,0}};
                for(int i=0;i<5;i++)
                    if(go[i][2]>=0)
                        dp[go[i][0]][go[i][1]][go[i][2]]=min(dp[go[i][0]][go[i][1]][go[i][2]],dp[day][play][coupon]+go[i][3]);
            }
    int ans=1e9;
    for(int day=played;day<=n+5;day++)
        for(int play=played;play<=played+5;play++)
            for(int coupon=0;coupon<=day/2;coupon++)
                ans=min(ans,dp[day][play][coupon]);
    printf("%d",ans);
    return 0;
}