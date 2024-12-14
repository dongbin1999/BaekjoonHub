#include<bits/stdc++.h>
using namespace std;
bool dp[151][151][451];
char s[155];
int albert[300],alice[300];
int ans;
void go(int l,int r,int x,bool b=0){
    if(l>r){if(x>150)ans=min(ans,x-150);return;}
    if(dp[l][r][x])return;
    dp[l][r][x]=1;
    if(b){
        go(l+1,r,x-alice[s[l]],!b);
        go(l,r-1,x-alice[s[r]],!b);
    }
    else{
        if(albert[s[l]])go(l+1,r,x+2,!b);
        else go(l,r-1,x+albert[s[r]],!b);
    }
}

void solve(){
    scanf("%s",s+1);int n=strlen(s+1);
    memset(dp,0,sizeof(dp));
    ans=1e9;
    go(1,n,150);
    printf("%d\n",ans==1e9?-1:ans);
}

int main(){
    string x="ALBERT",y="ALICE";
    for(auto i:x)albert[i]=2;for(auto i:y)alice[i]=1;
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}