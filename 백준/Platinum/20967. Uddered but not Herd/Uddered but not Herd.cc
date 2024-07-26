#include<bits/stdc++.h>
using namespace std;

char s[100002];
map<int,int> ma;
int a[26][26],dp[1<<20];

int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(!ma.count(s[i]))ma[s[i]]=ma.size();
        if(i)a[ma[s[i-1]]][ma[s[i]]]++;
    }
    int sz=ma.size();
    for(int i=0;i<1<<sz;i++){
        vector<int> v;
        for(int k=0;k<sz;k++)if(i>>k&1)v.push_back(k);
        for(int j=0;j<sz;j++){
            if(i>>j&1)continue;
            int add=0;
            for(auto k:v)add+=a[k][j];
            dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+add);
        }
    }
    printf("%d",n-dp[(1<<sz)-1]);
    return 0;
}