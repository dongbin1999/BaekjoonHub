#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char s[3002];
int dp[3001];
int main(){
    int n;scanf("%d %s",&n,s+1);
    for(int i=1;i<=n;i++){
        vector<int> t(i+1,0);
        if(s[i]=='P')
            for(int j=max(1,i-2);j<=min(n,i+2);j++){
                if(s[j]=='.') s[j]='X';
            }
        int mex=0;
        for(int x=1;x<=i;x++){
            int l=max(0,x-3),r=max(0,i-(x+2));
            t[dp[l]^dp[r]]++;
            while(t[mex])mex++;
        }
        dp[i]=mex;
    }

    vector<pii> v;
    int len=0,XOR=0;
    for(int i=1;i<=n+1;i++){
        if(s[i]=='.')len++;
        else v.push_back({i-len,len}),XOR^=dp[len],len=0;
    }

    vector<int> win;
    for(int i=1;i<=n;i++){
        if(s[i]=='P') continue;
        if(i>=3&&i<=n&&s[i-1]=='P'&&s[i-2]=='P')win.push_back(i);//PP'.'
        else if(i>=2&&i<=n-1&&s[i-1]=='P'&&s[i+1]=='P')win.push_back(i);//P'.'P
        else if(i>=1&&i<=n-2&&s[i+1]=='P'&&s[i+2]=='P')win.push_back(i);//'.'PP
    }

    if(!win.empty()){
        printf("WINNING\n");
        for(auto i:win)printf("%d ",i);
        return 0;
    }
    else if(!XOR)return !printf("LOSING");

    for(auto [start,len]:v){
        XOR^=dp[len];
        for(int put=1;put<=len;put++){
            int l=max(0,put-3),r=max(0,len-(put+2));
            if(XOR==(dp[l]^dp[r]))win.push_back(start+put-1);
        }
        XOR^=dp[len];
    }

    if(!win.empty()){
        printf("WINNING\n");
        for(auto i:win)printf("%d ",i);
    }
    else printf("LOSING");
    return 0;
}
