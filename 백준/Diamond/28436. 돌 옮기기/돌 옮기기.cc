#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[500002];
void solve(){
    scanf("%s",s);int n=strlen(s);
    ll ans=0,bw=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='B')bw=min(0ll,bw-1);
        else if(s[i]=='W')bw=max(0ll,bw+1);
        else ans+=bw;
    }
    printf(ans>0?"WHITE\n":"BLACK\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}