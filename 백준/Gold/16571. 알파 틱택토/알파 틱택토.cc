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

struct element
{
    int num,a[3][3];
};

int go(element e)//0:win,1:lose,2:draw
{
    for(int i=0;i<3;i++)
    {
        if(e.a[i][0]==1&&e.a[i][1]==1&&e.a[i][2]==1)//x로 채워짐.
            return e.num%2;//홀수면 o가 놓을차례. 진거임.
        if(e.a[0][i]==1&&e.a[1][i]==1&&e.a[2][i]==1)//x로 채워짐.
            return e.num%2;//홀수면 o가 놓을차례. 진거임.
        if(e.a[i][0]==2&&e.a[i][1]==2&&e.a[i][2]==2)//o로 채워짐.
            return 1-(e.num%2);//홀수면 o가 놓을차례. 이긴거임.
        if(e.a[0][i]==2&&e.a[1][i]==2&&e.a[2][i]==2)//o로 채워짐.
            return 1-(e.num%2);//홀수면 o가 놓을차례. 이긴거임.
    }
    if(e.a[0][0]==1&&e.a[1][1]==1&&e.a[2][2]==1)//x로 채워짐.
        return e.num%2;//홀수면 o가 놓을차례. 진거임.
    if(e.a[0][0]==2&&e.a[1][1]==2&&e.a[2][2]==2)//o로 채워짐.
        return 1-(e.num%2);//홀수면 o가 놓을차례. 이긴거임.
    if(e.a[2][0]==1&&e.a[1][1]==1&&e.a[0][2]==1)//x로 채워짐.
        return e.num%2;//홀수면 o가 놓을차례. 진거임.
    if(e.a[2][0]==2&&e.a[1][1]==2&&e.a[0][2]==2)//o로 채워짐.
        return 1-(e.num%2);//홀수면 o가 놓을차례. 이긴거임.
    if(e.num==9)
        return 2;//비김.
    map<int,int> ma;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            element to=e;
            to.num++;
            if(to.a[i][j]==0)
            {
                to.a[i][j]=e.num%2+1;
                int temp=go(to);
                if(temp<2)
                    temp=1-temp;
                ma[temp]++;
            }
        }
    if(ma[0]>0)//내가 이길수있음.
        return 0;
    else if(ma[2]>0)//내가 비길수있음.
        return 2;
    else return 1;//질수밖에없음.
}

int main()
{
    element e;
    e.num=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            scanf("%d",&e.a[i][j]);
            if(e.a[i][j]!=0)
                e.num++;
        }
    int ans = go(e);
    if(ans==0)//내가 이길수있음.
        printf("W");
    else if(ans==2)//내가 비길수있음.
        printf("D");
    else printf("L");
    return 0;
}