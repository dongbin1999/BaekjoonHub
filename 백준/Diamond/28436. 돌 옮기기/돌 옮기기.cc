#include <bits/stdc++.h>
using namespace std;
char s[1<<19];
void solve(){
    scanf("%s",s+1);
    long long a=0,x=0;
    for(int i=strlen(s+1);i;i--)
        if(s[i]=='B')x=min(0ll,x-1);
        else if(s[i]=='W')x=max(0ll,x+1);
        else a+=x;
    printf(a>0?"WHITE\n":"BLACK\n");
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}