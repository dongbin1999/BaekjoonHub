#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
char s[2000][2001];
int main(){
    int a,b;scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)scanf("%s",s[i]);
    int ans=1;
    for(int i=0;i<a;i++)for(int j=0;j<b;j++){
        int x=0;
        if(!i)x++;else if(s[i-1][j]==s[i][j])x++;
        if(i+1==a)x++;else if(s[i+1][j]==s[i][j])x++;
        if(!j)x++;else if(s[i][j-1]==s[i][j])x++;
        if(j+1==b)x++;else if(s[i][j+1]==s[i][j])x++;
        if(x==4)ans=(ans*2)%mod;
    }
    printf("%d",ans);
}